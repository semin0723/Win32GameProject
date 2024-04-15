#pragma once
#include "Win32GameProject.h"

class RenderSystem
{
public:
	HDC _hdc;
	HDC _frontDC;
	HDC _backDC;
	HWND _hWnd;
	HINSTANCE _hInstance;

	RenderSystem();
	~RenderSystem();

	static RenderSystem* GetInstance();
	static void DestroyInstance();

	void ScreenClear();

private:
	static RenderSystem* instance;
};