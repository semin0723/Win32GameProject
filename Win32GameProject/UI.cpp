#include "UI.h"
#include "LobbyScene.h"
#include <iostream>

UI::UI()
{
	_textlen = 0;
}

UI::~UI()
{
}

void UI::update() {
	char str[10];
	sprintf_s(str, "%d", LobbyScene::GetInstance()->GetMineCount());
	size_t tmp;
	int len = strlen(str);
	_text = new wchar_t[10];
	mbstowcs_s(&tmp, _text, 10, str, len);
	_textlen = len;
}

void UI::render(HDC mainDC, HINSTANCE hIns) {
	SetTextAlign(mainDC, TA_CENTER);
	TextOut(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, _text, _textlen);
}