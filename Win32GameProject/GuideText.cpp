#include "GuideText.h"
#include <iostream>

GuideText::GuideText()
{
}

GuideText::~GuideText()
{
}

void GuideText::update()
{
	_text = L"스마일 버튼을 눌러 게임 시작, 재시작 하십시오.";
}

void GuideText::render(HDC mainDC, HINSTANCE hIns)
{
	SetTextAlign(mainDC, TA_CENTER);
	TextOut(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, _text, 27);
}
