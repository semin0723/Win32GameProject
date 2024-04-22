#include "RenderSystem.h"

RenderSystem* RenderSystem::instance = nullptr;

RenderSystem::RenderSystem() {
	_hInstance = global::GetWinApp().GetInstance();
	_hWnd = global::GetWinApp().GetWindow();
	_hdc = GetDC(_hWnd);
	_backDC = CreateCompatibleDC(_hdc);
	GetClientRect(_hWnd, &_rect);
}

RenderSystem::~RenderSystem() {
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

void RenderSystem::StartDraw() {
	_MainBitmap = LoadBitmap(_hInstance, MAKEINTRESOURCE(WHITE_BOARD));
	_OldBitmap = (HBITMAP)SelectObject(_backDC, _MainBitmap);
}

void RenderSystem::EndDraw() {
	BitBlt(_hdc, _rect.left, _rect.top, _rect.right - _rect.left, _rect.bottom - _rect.top, _backDC, 0, 0, SRCCOPY);
	SelectObject(_backDC, _OldBitmap);
	DeleteObject(_MainBitmap);
}