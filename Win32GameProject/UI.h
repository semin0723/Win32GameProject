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

// TODO: UI 텍스트의 폰트 사이즈를 키우고, 각 버튼에 대해 도움말 문구도 추가합니다.