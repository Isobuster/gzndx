#ifndef GZIndexStructsH
#define GZIndexStructsH
//---------------------------------------------------------------------------
/*

The *.gzndx format was created by:
Peter@Smart-Projects.net
Author of www.isobuster.com

All hail to Mark Adler who makes random access in *.gz files possible:
https://github.com/madler/zlib/blob/master/examples/zran.h
https://github.com/madler/zlib/blob/master/examples/zran.c

Permission is granted to anyone to use this header and file format for any purpose,
including commercial applications, and to alter it and redistribute it
freely, subject to the following restrictions:

  1. The origin of this header and file format must not be misrepresented;
	 you must not claim that you wrote it. If you use it in software,
     in a product, an acknowledgment in the product documentation would be
     appreciated but is not required.
  2. Altered versions must be plainly marked as such, and must not be
	 misrepresented as being the original.
  3. This notice may not be removed or altered from any source distribution.

*/
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
#pragma pack(1)
//---------------------------------------------------------------------------

#define WINSIZE 	32768						/* 32 KiB sliding window size */

struct GZIndexRecord
{
	unsigned __int64	Out ;					/* corresponding offset in uncompressed data */
	unsigned __int64	In ;					/* offset in (compressed) input file of first full byte */
	BYTE				Bits ;					/* number of bits (1-7) from byte at in-1, or 0 */
	BYTE				Data[WINSIZE] ;			/* preceding 32K of uncompressed data */
};


#define GZNDX_Sig       0x7865646E49205A47LL	/* "GZ Index" */
#define GZNDX_GZip      0x01					/* GZip file type, not pure Zlib */
#define GZNDX_Version   0x01					/* Current version */

struct GZIndexFileHeader
{
	unsigned __int64	Signature ;      		/* "GZ Index" */
	BYTE                Version ;           	/* GZNDX_Version */
	BYTE                Flags ;             	/* GZNDX_GZip (or not) */
	WORD                OffsetOfIndex ;			/* Immediately after this header, sizeof(GZIndexFileHeader) */
	unsigned __int64	Count ;             	/* Number of records in this index/file */
	unsigned __int64	UncompressedSize ;      /* Size when fully uncompressed */
};

//---------------------------------------------------------------------------
#pragma pack()
//---------------------------------------------------------------------------

#endif
//---------------------------------------------------------------------------

