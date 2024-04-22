#include "Title.h"

Title::Title()
{
}

Title::~Title()
{
}

void Title::update()
{
}

void Title::render(HDC mainDC, HINSTANCE hIns)
{
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = LoadBitmap(hIns, MAKEINTRESOURCE(GameObject::GetResourceID()));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);

	BitBlt(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);

	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}
