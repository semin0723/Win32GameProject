#include "Tile.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::update() {

}

void Tile::render(HDC mainDC, HINSTANCE hIns) {
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = LoadBitmap(hIns, MAKEINTRESOURCE(GameObject::GetResourceID()));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 30; x++) {
			BitBlt(mainDC, 32 + myInfo.bmWidth * x, 96 + myInfo.bmHeight * y, myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);
		}
	}
	/*BitBlt(mainDC, (int)(GameObject::GetLocation()._x - myInfo.bmWidth / 2.0f), (int)(GameObject::GetLocation()._y - myInfo.bmHeight / 2.0f),
		myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);*/
	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}