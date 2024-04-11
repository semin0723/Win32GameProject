#pragma once
#include "Win32GameProject.h"

class RenderSystem
{
public:
	static RenderSystem* GetInstance();
	static void DestroyInstance();

private:
	HDC _hdc;
	HDC _frontDC;
	HDC _backDC;
	HWND _hWnd;
	HINSTANCE _hInstance;

	static RenderSystem* instance;
};