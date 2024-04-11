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