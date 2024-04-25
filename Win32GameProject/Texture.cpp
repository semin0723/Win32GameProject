#include "Texture.h"

Texture::Texture() : _DC(0), _Bitmap(0), _BitInfo{}
{
}

Texture::~Texture()
{
	DeleteDC(_DC);
	DeleteObject(_Bitmap);
}

void Texture::Load()
{
	_Bitmap = (HBITMAP)LoadImage(nullptr, GameResource::GetPath(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(_Bitmap, sizeof(BITMAP), (BITMAP*)&_BitInfo);

	_DC = CreateCompatibleDC(RenderSystem::GetInstance()->_hdc);
	HBITMAP prev = (HBITMAP)SelectObject(_DC, _Bitmap);
	DeleteObject(prev);
}
