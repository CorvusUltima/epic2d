#include "Sprite.h"
#include"ChiliWin.h"
#include<fstream>
#include"assert.h"

Sprite::Sprite(const std::string& filename)
{
	std::ifstream file(filename, std::ios::binary);
	assert(file);

	BITMAPFILEHEADER bmFileheader;

	file.read(reinterpret_cast<char*>(&bmFileheader), sizeof(bmFileheader));

	BITMAPINFOHEADER bmInfoHeader;

	file.read(reinterpret_cast<char*>(&bmInfoHeader), sizeof(bmInfoHeader));

	assert(bmInfoHeader.biBitCount == 24);
	assert(bmInfoHeader.biCompression == BI_RGB);

	 width = bmInfoHeader.biWidth;
	 height = bmInfoHeader.biHeight;

	pPixels = new Color[width * height];

	file.seekg(bmFileheader.bfOffBits); // bm file starts with offset in pixel count  

	const int padding = (4 - (width * 3) % 4) % 4;  

	for (int y = height - 1; y >= 0; y--)
	{
		for (int x = 0; x < width; x++)
		{	
			const unsigned char b = file.get();
			const unsigned char g = file.get();
			const unsigned char r = file.get();

			PutPixel(x, y, Color(b,g,r ));
		}
		file.seekg(padding, std::ios::cur);
	}
}

Sprite::Sprite(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width*height])
{
}

Sprite::Sprite(const Sprite& rhs)
	:
	Sprite(rhs.width,rhs.height)
{

	const int nPixels = width * height;
	for (int i = 0; i < nPixels; i++)
	{
		pPixels[i] = rhs.pPixels[i];
	}

}

Sprite::~Sprite()
{
	delete[] pPixels;
	pPixels = nullptr;
}

Sprite& Sprite::operator=(const Sprite& rhs)


{
	if (pPixels == rhs.pPixels)
	{
		return *this;
	}
	else

		width = rhs.width;
	    height = rhs.height;
	    delete[] pPixels;
	    pPixels = new Color[width * height];

		const int nPixels = width * height;
		for (int i = 0; i < nPixels; i++)
		{
			pPixels[i] = rhs.pPixels[i];
		}

	    return *this;
	
}

void Sprite::PutPixel(int x, int y, Color c)
{

	pPixels[y * width + x] = c;

}

Color Sprite::GetPixel(int x, int y) const
{
	return pPixels[y * width + x];
}

int Sprite::GetWidth() const
{
	return width;
}

int Sprite::GetHeight() const
{
	return height;
}
