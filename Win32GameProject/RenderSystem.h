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

	RenderSystem() {}
	~RenderSystem() {}

	static RenderSystem* GetInstance();
	static void DestroyInstance();

	void DrawBitMap(const int x, const int y, const int id);

private:
	static RenderSystem* instance;
};