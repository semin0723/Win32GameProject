#include "RenderSystem.h"

RenderSystem* RenderSystem::instance = nullptr;

RenderSystem::RenderSystem() {
	_hInstance = global::GetWinApp().GetInstance();
	_hWnd = global::GetWinApp().GetWindow();
	_hdc = GetDC(_hWnd);
	_frontDC = CreateCompatibleDC(_hdc);
	_backDC = CreateCompatibleDC(_hdc);
}

RenderSystem::~RenderSystem() {
	DeleteDC(_frontDC);
	DeleteDC(_backDC);
	ReleaseDC(_hWnd, _hdc);
}

RenderSystem* RenderSystem::GetInstance() {
	if (instance == nullptr) {
		instance = new RenderSystem();
	}
	return instance;
}

void RenderSystem::DestroyInstance() {
	if (instance != nullptr) {
		delete instance;
		instance = nullptr;
	}
}

void RenderSystem::DrawBitMap(const int x, const int y, const int id) {
	HBITMAP MainBitmap, OldBitmap;
	BITMAP Bitmapinfo;
	int bmWidth, bmHeight;
	MainBitmap = LoadBitmap(RenderSystem::GetInstance()->_hInstance, MAKEINTRESOURCE(id));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&Bitmapinfo);
	bmWidth = Bitmapinfo.bmWidth;
	bmHeight = Bitmapinfo.bmHeight;

	OldBitmap = (HBITMAP)SelectObject(RenderSystem::GetInstance()->_hdc, MainBitmap);
	BitBlt(RenderSystem::GetInstance()->_hdc, 
		x - bmWidth / 2, y - bmHeight / 2, bmWidth, bmHeight, 
		RenderSystem::GetInstance()->_backDC, 0, 0, SRCCOPY);
	SelectObject(RenderSystem::GetInstance()->_backDC, OldBitmap);
	DeleteObject(MainBitmap);
}