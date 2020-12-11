#include "CutBMP.h"
// read
bool havecolortable(_header header, _DIB DIB)
{
	return (14 + DIB.Size == header.PixelOffset) ? false : true;
}

void readheader(ifstream& file, _header& header)
{
	file.seekg(0, SEEK_SET);
	file.read((char*)&header, 14);
}

void readDIB(ifstream& file, _DIB& DIB)
{
	int32_t size;
	file.seekg(14, SEEK_SET);
	file.read((char*)&size, 4);
	file.seekg(14, SEEK_SET);
	file.read((char*)(&DIB), size);
}

int getPixelArray(ifstream& file, unsigned char**& pixelcolor, int offset, int Width, int Height, int depth)
{
	int byteperpixel = depth / 8;

	int pad = (4 - (Width * byteperpixel) % 4) % 4;
	//int pad = (byteperpixel * Width) - (byteperpixel * Width) / 4 * 4;

	// allocate for pixel array
	pixelcolor = new (nothrow) unsigned char* [Height];
	if (pixelcolor == NULL)
		return -1;
	else
	{
		for (int i = 0; i < Height; ++i)
			pixelcolor[i] = NULL;
		for (int i = 0; i < Height; ++i)
			pixelcolor[i] = new (nothrow) unsigned char[Width * byteperpixel];
	}
	for (int i = 0; i < Height; ++i)
		if (pixelcolor[i] == NULL)
		{
			for (int j = 0; j < i; ++j)
				delete[] pixelcolor[j];
			delete[] pixelcolor;
			return -1;
		}
	char tmp[4] = { 0,0,0,0 };

	file.seekg(offset, SEEK_SET);
	for (int i = Height - 1; i >= 0; --i)
	{
		file.read((char*)pixelcolor[i], byteperpixel * (int64_t)Width);
		if (pad != 0)
			file.read(tmp, pad);
	}
	return 0;
}

void readcolortable(ifstream& file, _header header, _DIB DIB, unsigned char*& colortable)
{
	int colortablesize = header.PixelOffset - DIB.Size - 14;
	colortable = new unsigned char[colortablesize];
	file.read((char*)colortable, colortablesize);
}

// write
void writeheader(ofstream& file, _header& header)
{
	file.seekp(0, SEEK_SET);
	file.write((char*)&header, 14);
}

void writeDIB(ofstream& file, _DIB& DIB)
{
	int size = DIB.Size;
	file.seekp(14, SEEK_SET);
	file.write((char*)&DIB, size);
}

string createFILEname(int first, int second, string SourceImg)
{
	string s = SourceImg;
	int pos = s.size();
	while (pos >= 0)
	{
		if (s[pos] == '.')
		{
			s = s.substr(0, pos);
			break;
		}
		pos--;
	}
	pos = 0;
	while (pos < static_cast<int>(s.size()))
	{
		if (s[pos] == '\\')
		{
			s = s.substr(pos, s.size());
			break;
		}
		pos++;
	}
	string s1 = to_string(first);
	string s2 = to_string(second);
	s = "Resource\\Image\\" + s2 + "-" + s1 + ".bmp";
	return s;
}

void writecolortable(ofstream& file, _header header, _DIB DIB, unsigned char*& colortable)
{
	int colortablesize = header.PixelOffset - DIB.Size - 14;
	file.seekp(14 + (int64_t)DIB.Size, SEEK_SET);
	file.write((char*)colortable, colortablesize);
}

int writebmp(unsigned char** pixelcolor, _header header, _DIB DIB, unsigned char* colortable, int i, int j, int w, int h, int depth, string SourceImg)
{
	string filenamestring = createFILEname(i - 1, j - 1, SourceImg);
	ofstream ftmp(filenamestring, ios::binary | ios::out);
	if (!ftmp.is_open())
	{
		return -1;
	}

	int bitperpixel = depth / 8;
	int subw = DIB.ImgWidth / w;
	int subh = DIB.ImgHeight / h;
	int startsubH = j * subh;
	int startsubW = (i - 1) * subw * bitperpixel;

	if (i == w)
		subw = DIB.ImgWidth - DIB.ImgWidth / w * (w - 1);
	if (j == h)
		subh = DIB.ImgHeight - DIB.ImgHeight / h * (h - 1);

	int subpad = (4 - (subw * bitperpixel) % 4) % 4;
	int sublinesize = bitperpixel * subw + subpad;
	char tmp[4] = { 0,0,0,0 };
	DIB.ImgHeight = subh;
	DIB.ImgWidth = subw;
	DIB.PixelArraySize = subh * sublinesize;
	header.Fizesize = 14 + DIB.Size + DIB.PixelArraySize;

	writeheader(ftmp, header);
	writeDIB(ftmp, DIB);
	if (havecolortable(header, DIB))
		writecolortable(ftmp, header, DIB, colortable);

	ftmp.seekp(header.PixelOffset, SEEK_SET);
	for (int y = startsubH - 1; y >= startsubH - subh; --y)
	{
		ftmp.write((char*)pixelcolor[y] + startsubW, bitperpixel * (int64_t)subw);
		if (subpad != 0)
			ftmp.write(tmp, subpad);
	}
	ftmp.close();
	return 0;
}

int divibmp(_header header, _DIB DIB, unsigned char* colortable, unsigned char** pixelcolor, int w, int h, int depth, string SourceImg)
{
	int err = 0;
	for (int i = 1; i <= w; ++i)
	{
		for (int j = 1; j <= h; ++j)
		{
			err = writebmp(pixelcolor, header, DIB, colortable, i, j, w, h, depth, SourceImg);
			if (err == -1)
			{
				return err;
			}
		}
	}
	return 0;
}

int CutBMP_(string Source, int split_height, int split_width, int% image_height, int% image_width)
{
	string SourceImg = Source;

	ifstream file(SourceImg, ios::binary | ios::in);
	if (!file.is_open())
	{
		return -1;
	}

	_header header;
	_DIB DIB;
	unsigned char* colortable = nullptr;
	unsigned char** pixelcolor;

	// read header, DIB, and colortable if present
	readheader(file, header);
	readDIB(file, DIB);
	if (havecolortable(header, DIB))
	{
		readcolortable(file, header, DIB, colortable);
	}

	int errcheck = getPixelArray(file, pixelcolor, header.PixelOffset, DIB.ImgWidth, DIB.ImgHeight, DIB.ColorDepth);
	if (errcheck == -1)
		return -1;

	image_height = DIB.ImgHeight;
	image_width = DIB.ImgWidth;
	errcheck = divibmp(header, DIB, colortable, pixelcolor, split_width, split_height, DIB.ColorDepth, SourceImg);
	if (errcheck == -1)
		return -1;

	if (havecolortable(header, DIB))
		delete[] colortable;
	for (int i = 0; i < DIB.ImgHeight; ++i)
		delete[] pixelcolor[i];
	delete[] pixelcolor;

	return 0;
}