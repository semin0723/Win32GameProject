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
	_MainBitmap = CreateCompatibleBitmap(_hdc, _rect.right - _rect.left, _rect.bottom - _rect.top);
	_OldBitmap = (HBITMAP)SelectObject(_backDC, _MainBitmap);
	FillRect(_backDC, &_rect, (HBRUSH)GetStockObject(WHITE_BRUSH));
}

void RenderSystem::EndDraw() {
	BitBlt(_hdc, _rect.left, _rect.top, _rect.right - _rect.left, _rect.bottom - _rect.top, _backDC, 0, 0, SRCCOPY);
	SelectObject(_backDC, _OldBitmap);
	DeleteObject(_MainBitmap);
}
/*
	TODO: 
	������ ���� :
	1. ������Ʈ ID, ������ ��ǥ �޾ƿ���.
	UI, �� -> �������� : �»��
	����, Ÿ�� -> �������� : �߾�
	2. �ش� ID�� ������� ���ҽ� �ҷ��ͼ� �׸���.
*/