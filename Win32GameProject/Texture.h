#pragma once
#include "ResourceManager.h"
#include "RenderSystem.h"

class Texture : public ResourceManager {
public:
	Texture();
	~Texture();

	void Load(const wchar_t* path);

	LONG Width() { return _BitInfo.bmWidth; }
	LONG Height() { return _BitInfo.bmHeight; }
	HDC GetDC() { return _DC; }

private:
	HDC _DC;
	HBITMAP _Bitmap;
	BITMAP _BitInfo;
};