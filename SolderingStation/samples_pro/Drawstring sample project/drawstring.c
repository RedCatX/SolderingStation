/*********************************************************************
 * Example code to draw character with "General *.c file"            *
 *                      == http://www.iseasoft.com/                  *
 *                      == support@iseatech.com                      *
 *                                                                   *
 * NOTE: BitFontCreator can generate various format data,            *
 *       This sample code is limited to the format blow:             *
 *       Font Type:     1-bpp, 2-bpp, 4-bpp                          *
 *       Data length:   8 bit                                        *
 *       Bit order:     Big Endian, Little Endian                    *
 *       Scan based:    Row, Column                                  *
 *       Scan prefered: Row, Column                                  *
 *       Data Packed:   No                                           *
 *********************************************************************/
#include <windows.h>
#include "drawstring.h"

int GetFontBpp(unsigned long FontType)
{
	// bits per pixel
	int bpp = -1;

	switch(FontType & 0xFF)
	{
	case FONTTYPE_MONO:
	case FONTTYPE_PROP:
		bpp = 1;
		break;
	case FONTTYPE_MONO_AA2:
	case FONTTYPE_PROP_AA2:
		bpp = 2;
		break;
	case FONTTYPE_MONO_AA4:
	case FONTTYPE_PROP_AA4:
		bpp = 4;
		break;
	case FONTTYPE_MONO_AA8:
	case FONTTYPE_PROP_AA8:
		bpp = 8;
		break;
	}

	return bpp;
}

int GetFontEndian(unsigned long FontType)
{
	// 0: Big Endian (default)
	// 1: Little Endian
	int endian = (FontType & LITTLE_ENDIAN) > 0 ? 1 : 0;

	return endian;
}

int GetFontScanBase(unsigned long FontType)
{
	// 0: Row (default)
	// 1: Column
	int scanBase = (FontType & COLUMN_BASED) > 0 ? 1 : 0;

	return scanBase;
}

int GetFontScanPrefer(unsigned long FontType)
{
	// 0: Row (default)
	// 1: Column
	int scanPrefer = (FontType & COLUMN_PREFERRED) > 0 ? 1 : 0;

	return scanPrefer;
}

int GetFontDataPack(unsigned long FontType)
{
	// 0: No (default)
	// 1: Yes
	int dataPack = (FontType & DATA_PACKED) > 0 ? 1 : 0;

	return dataPack;
}

int GetFontHeight(const BFC_FONT *pFont)
{
	int height = -1;

	if(pFont != 0)
		height = pFont->FontHeight;

	return height;
}

const BFC_CHARINFO* GetCharInfo(const BFC_FONT *pFont, unsigned short ch)
{
	const BFC_CHARINFO	*pCharInfo = 0;
	const BFC_FONT_PROP *pProp = pFont->p.pProp;
	unsigned short first_char, last_char;

	if(pFont == 0 || pFont->p.pProp == 0)
		return 0;

	while(pProp != 0)
	{
		first_char = pProp->FirstChar;
		last_char = pProp->LastChar;
		pCharInfo = pProp->pFirstCharInfo;

		if( ch >= first_char && ch <= last_char )
		{
			// the character "ch" is inside this range,
			// return this char info, and not search anymore.
			pCharInfo = pCharInfo + (ch - first_char);
			return pCharInfo;
		}
		else 
		{
			// the character "ch" is not in this range
			// so search it in the next range
			pProp = pProp->pNextProp;
		}
	}

	// if the character "ch" is not rendered in this font,
	// we use the first character in this font as the default one.
	if( pCharInfo == 0 )
	{
		pProp = pFont->p.pProp;
		pCharInfo = pProp->pFirstCharInfo;
	}

	return pCharInfo;
}

// The raw draw pixel function in your LCD.
// you should replace this function with your own based on your LCD.
void LCD_DrawPixel(HDC hdc, int x, int y, int color)
{
	// in Windows application, the code looks like this:
	SetPixel(hdc, x, y, color);
}

unsigned long LCD_GetColorBasedPixel(int pixel, int bpp)
{
	unsigned char	r = 0;
	unsigned char	g = 0;
	unsigned char	b = 0;

	unsigned long color = 0;

	switch(bpp)
	{
	case 1:
		r = g = b = 255 * (1 - pixel);
		break;

	case 2:
		r = g = b = 255 * (3 - pixel) / 3;
		break;

	case 4:
		r = g = b = 255 * (15 - pixel) / 15;
		break;

	case 8:
		r = g = b = 255 - pixel;
		break;
	}

	color = ((r) | (g<<8) | (b<<16));

	return color;
}

int DrawChar(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch)
{
	int scanBase, scanPrefer, dataPack, flag;
	if( pFont == 0 )
		return 0;

	scanBase   = GetFontScanBase(pFont->FontType);
	scanPrefer = GetFontScanPrefer(pFont->FontType);
	dataPack   = GetFontDataPack(pFont->FontType);

	// make a flag for switch using conveniently.
	// | 15 | 14 | 13 | 12 | 11 | 10 | 9 | 8 | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
	// |                   |    scanBase     |   scanPrefer  |   dataPack    |
	flag = scanBase<<8 | scanPrefer<<4 | dataPack;
	switch(flag)
	{
	case 0x000: // row based, row preferred, unpacked
		return DrawChar_RowRowUnpacked(hdc, x0, y0, pFont, ch);
	case 0x110: // column based, column preferred, unpacked
		return DrawChar_ColColUnpacked(hdc, x0, y0, pFont, ch);

	// NOTE: the followings have not finished yet. 
	//       please write your own DrawChar_xxx functions.

	case 0x010: // row based, column preferred, unpacked
		break;
	case 0x100: // Column based, Row preferred, unpacked
		break;

	case 0x001: // row based, row preferred, packed
		break;
	case 0x111: // column based, column preferred, packed
		break;
	case 0x011: // row based, column preferred, packed
		break;
	case 0x101: // Column based, Row preferred, packed
		break;
	}

	return 0;
}

// return: advance width of this character
int DrawChar_RowRowUnpacked(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch)
{
	// 1. find the character information first
	const BFC_CHARINFO *pCharInfo = GetCharInfo(pFont, ch);
	
	if( pCharInfo != 0 )
	{
		int height = pFont->FontHeight;
		int width = pCharInfo->Width;
		int data_size = pCharInfo->DataSize;                // # bytes of the data array
		const unsigned char *pData = pCharInfo->p.pData8;   // pointer to data array

		int bpp = GetFontBpp(pFont->FontType);              // how many bits per pixel
		int bytesPerLine = (width * bpp + 7) / 8;           // # bytes in a row
		int bLittleEndian = (GetFontEndian(pFont->FontType)==1);

		int x, y, col;
		unsigned char data, pixel, bit;
		unsigned long color;

		// 2. draw all the pixels in this character
		for(y=0; y<height; y++)
		{
			for(x=0; x<width; x++)
			{
				col = (x * bpp) / 8;       // byte index in the line
				data = pData[y * bytesPerLine + col];

				// every BYTE (8 bits) data includes 8/bpp pixels,
				// we need to get each pixel color index (0,1,2,3... based on bpp) from the BYTE data
				pixel = data;
				
				// bit index in the BYTE
				// For 1-bpp: bit =  x % 8 (Big Endian),   7 -  x % 8 (Little Endian)
				// For 2-bpp: bit = 2x % 8 (Big Endian),   6 - 2x % 8 (Little Endian)
				// For 4-bpp: bit = 4x % 8 (Big Endian),   4 - 4x % 8 (Little Endian)
				bit = bLittleEndian ? (8-bpp)-(x*bpp)%8 : (x*bpp)%8;

				pixel = pixel<<bit;               // clear left pixels
				pixel = pixel>>(8/bpp-1)*bpp;     // clear right pixels

				// draw this pixel
				color = LCD_GetColorBasedPixel(pixel, bpp);
				LCD_DrawPixel(hdc, x0+x, y0+y, color);
			}
		}

		return width;
	}

	return 0;
}

// return: advance width of this character
int DrawChar_ColColUnpacked(HDC hdc, int x0, int y0, const BFC_FONT *pFont, unsigned short ch)
{
	// 1. find the character information first
	const BFC_CHARINFO *pCharInfo = GetCharInfo(pFont, ch);
	
	if( pCharInfo != 0 )
	{
		int height = pFont->FontHeight;
		int width = pCharInfo->Width;
		int data_size = pCharInfo->DataSize;                // # bytes of the data array
		const unsigned char *pData = pCharInfo->p.pData8;   // pointer to data array

		int bpp = GetFontBpp(pFont->FontType);              // how many bits per pixel
		int bytesPerLine = (height * bpp + 7) / 8;          // # bytes in a row
		int bLittleEndian = (GetFontEndian(pFont->FontType)==1);

		int x, y, col;
		unsigned char data, pixel, bit;
		unsigned long color;

		// 2. draw all the pixels in this character
		for(x=0; x<width; x++)
		{
			for(y=0; y<height; y++)
			{
				col = (y * bpp) / 8;       // byte index in the line
				data = pData[x * bytesPerLine + col];

				// every BYTE (8 bits) data includes 8/bpp pixels,
				// we need to get each pixel color index (0,1,2,3... based on bpp) from the BYTE data
				pixel = data;
				
				// bit index in the BYTE
				// For 1-bpp: bit =  y % 8 (Big Endian),   7 -  y % 8 (Little Endian)
				// For 2-bpp: bit = 2y % 8 (Big Endian),   6 - 2y % 8 (Little Endian)
				// For 4-bpp: bit = 4y % 8 (Big Endian),   4 - 4y % 8 (Little Endian)
				bit = bLittleEndian ? (8-bpp)-(y*bpp)%8 : (y*bpp)%8;

				pixel = pixel<<bit;               // clear left pixels
				pixel = pixel>>(8/bpp-1)*bpp;     // clear right pixels

				// draw this pixel
				color = LCD_GetColorBasedPixel(pixel, bpp);
				LCD_DrawPixel(hdc, x0+x, y0+y, color);
			}
		}

		return width;
	}

	return 0;
}

void DrawStringW(HDC hdc, int x0, int y0, const BFC_FONT *pFont, const unsigned short *str, int length)
{
	int x = x0;
	int y = y0;
	int i = 0;
	int width = 0;
	unsigned short ch = 0;

	if( pFont == 0 || str == 0 || hdc ==0 )
		return;

	for(i=0; i<length; i++)
	{
		ch = str[i];

		width = DrawChar(hdc, x, y, pFont, ch);
		x += width;
	}
}

void DrawStringA(HDC hdc, int x0, int y0, const BFC_FONT *pFont, const char *str, int length)
{
	int x = x0;
	int y = y0;
	int i = 0;
	int width = 0;
	char ch = 0;

	if( pFont == 0 || str == 0 || hdc ==0 )
		return;

	for(i=0; i<length; i++)
	{
		ch = str[i];

		width = DrawChar(hdc, x, y, pFont, ch);
		x += width;
	}
}