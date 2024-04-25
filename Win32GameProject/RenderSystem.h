#pragma once
#include "Win32GameProject.h"

class RenderSystem
{
public:
	HDC _hdc;
	HDC _backDC;
	HWND _hWnd;
	RECT _rect;
	HINSTANCE _hInstance;
	HBITMAP _MainBitmap;
	HBITMAP _OldBitmap;

	RenderSystem();
	~RenderSystem();

	static RenderSystem* GetInstance();
	static void DestroyInstance();

	void InitRender();

	void StartDraw();
	void EndDraw();

private:
	static RenderSystem* instance;
};