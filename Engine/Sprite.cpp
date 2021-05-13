#include "Sprite.h"

Sprite::Sprite(int width, int height)
	:
	width(width),
	height(height),
	pPixels(new Color[width*height])
{
}

Sprite::Sprite(const Sprite& rhs)

{
}
