# gzndx

A *.gzndx file is an index file to easily and randomly access *.gz files.

A *.gz file is a monolythic block of compressed data.  The format implements no type of index to quickly jump to an uncompressed location in the file.  This makes random access impossible, unless the file is fully decompressed first.

Mark Adler created some excellent code that decompresses a *.gz file in temporary memory to create an index (kept in memory)<br>
https://github.com/madler/zlib/blob/master/examples/zran.h<br>
https://github.com/madler/zlib/blob/master/examples/zran.c<br>
Once this is done it is possible to access the file randomly using the index that was created in memory

The *.gzndx format takes this a step further by dumping the entirity of the memory-stored index into a file.  
An application, when it loads a *.gz file, can now first look for a *.gzndx file with same name, and if it exists can use its contents rather than having to decompress the *.gz file in memory first, to generate a new index.

The *.gzndx format starts with a small header, followed by a byte per byte copy of all 'point' records stored in memory.<br>
The *.gzndx header data is detailed in GZIndexStructs.h (GZIndexFileHeader).

For example files: IsoBuster versions 5.3 and up create *.gzndx files on the fly when opening *.gz files (Check Settings: Options / Image Files / ISO - BIN - TAO - GZ)
