#include "Monster.h"

Monster::Monster()
{
}

Monster::~Monster()
{
}

void Monster::update() {
	Vector3 loc = GameObject::GetLocation();
	if (loc._x <= 700) {
		GameObject::SetLocation(GameObject::GetLocation() + Vector3(0.5f, 0, 0));
	}
}

void Monster::render(HDC mainDC, HINSTANCE hIns) {
	
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = LoadBitmap(hIns, MAKEINTRESOURCE(GameObject::GetResourceID()));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);
	BitBlt(mainDC, (int)(GameObject::GetLocation()._x - myInfo.bmWidth / 2.0f), (int)(GameObject::GetLocation()._y - myInfo.bmHeight / 2.0f),
		myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);
	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}