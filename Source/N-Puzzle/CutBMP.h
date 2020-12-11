#pragma once
#include <stdint.h>
#include <fstream>
#include <string>
using std::string;
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::to_string;
using std::ios;
using std::nothrow;
using std::nothrow_t;


#pragma pack (push, 1)
struct _header
{
	char Signature[2];
	int32_t Fizesize;
	int16_t Reserved1;
	int16_t Reserved2;
	int32_t PixelOffset;
};

struct _DIB
{
	int32_t Size;
	int32_t ImgWidth;
	int32_t ImgHeight;
	int16_t ColorPlanes;
	int16_t ColorDepth;
	int32_t CompressAlgorithm;
	int32_t PixelArraySize;
	int32_t HorizontalResolution;
	int32_t VerticalResolution;
	int32_t NumberOfColor;
	int32_t NumberOfImportantColor;
};

#pragma pack(pop)

bool havecolortable(_header header, _DIB DIB);
void readheader(ifstream& file, _header& header);
void readDIB(ifstream& file, _DIB& DIB);
int getPixelArray(ifstream& file, unsigned char**& pixelcolor, int offset, int Width, int Height, int depth);
void readcolortable(ifstream& file, _header header, _DIB DIB, unsigned char*& colortable);

// write
void writeheader(ofstream& file, _header& header);
void writeDIB(ofstream& file, _DIB& DIB);
string createFILEname(int first, int second, string SourceImg);
void writecolortable(ofstream& file, _header header, _DIB DIB, unsigned char*& colortable);
int writebmp(unsigned char** pixelcolor, _header header, _DIB DIB, unsigned char* colortable, int j, int i, int w, int h, int depth, string SourceImg);
int divibmp(_header header, _DIB DIB, unsigned char* colortable, unsigned char** pixelcolor, int w, int h, int depth, string SourceImg);

int CutBMP_(string Source, int split_height, int split_width, int% image_height, int% image_width);