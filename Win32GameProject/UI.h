#pragma once

#include "GameObject.h"
#include "RenderSystem.h"
// TODO: UI 기본 클래스 생성

class UI : public GameObject
{
public:
	UI();
	~UI();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns, int x, int y);

private:
	wchar_t* _text;
	int _textlen;
};