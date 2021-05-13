#include "Sprite.h"

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
