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

void RenderSystem::ScreenClear() {
	HBITMAP MainBitmap, OldBitmap;
	BITMAP clear;
	HDC backDC = CreateCompatibleDC(_hdc);
	MainBitmap = LoadBitmap(RenderSystem::GetInstance()->_hInstance, MAKEINTRESOURCE(IDB_BITMAP2));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&clear);
	OldBitmap = (HBITMAP)SelectObject(_hdc, MainBitmap);
	BitBlt(_hdc, 0, 0, clear.bmWidth, clear.bmHeight, backDC, 0, 0, SRCCOPY);
	SelectObject(backDC, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(backDC);
}

/*
	TODO: 
	랜더링 순서 :
	1. 오브젝트 ID, 랜더링 좌표 받아오기.
	UI, 씬 -> 시작지점 : 좌상단
	몬스터, 타워 -> 시작지점 : 중앙
	2. 해당 ID를 기반으로 리소스 불러와서 그리기.
*/