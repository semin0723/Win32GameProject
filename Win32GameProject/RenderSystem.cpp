#include "RenderSystem.h"
#include "SceneManager.h"
#include "globalheader.h"

RenderSystem* RenderSystem::instance = nullptr;

RenderSystem::RenderSystem() {
}

RenderSystem::~RenderSystem() {
	DeleteDC(_backDC);
	ReleaseDC(_hWnd, _hdc);
	DeleteObject(_MainBitmap);
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

void RenderSystem::InitRender() {
	_hInstance = global::GetWinApp().GetInstance();
	_hWnd = global::GetWinApp().GetWindow();
	_hdc = GetDC(_hWnd);
	_backDC = CreateCompatibleDC(_hdc);

	GetClientRect(_hWnd, &_rect);
	_MainBitmap = CreateCompatibleBitmap(_hdc, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight());
	_OldBitmap = (HBITMAP)SelectObject(_backDC, _MainBitmap);
	
	DeleteObject(_OldBitmap);
}

void RenderSystem::StartDraw() {
	//Rectangle(_backDC, -1, -1, _rect.right + 1, _rect.bottom + 1);
	PatBlt(_backDC, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), WHITENESS);
	SelectObject(_backDC, _MainBitmap);
}

void RenderSystem::EndDraw() {
	BitBlt(_hdc, 0, 0, global::GetWinApp().GetWidth(), global::GetWinApp().GetHeight(), _backDC, 0, 0, SRCCOPY);
}