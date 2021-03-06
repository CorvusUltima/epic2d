#pragma once
#include"Colors.h"
#include<String>
class Sprite
{
public:

	Sprite(const std::string& filename);
	Sprite(int width,int height);
	Sprite(const Sprite& rhs);
	~Sprite();
	Sprite& operator = (const Sprite& rhs);
	void PutPixel(int x, int y, Color c);
	Color GetPixel(int x, int y)const ;
	int GetWidth()const;
	int GetHeight()const;




private:

	int width;
	int height;
	Color* pPixels = nullptr;

};

