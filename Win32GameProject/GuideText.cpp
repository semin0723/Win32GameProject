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
	_text = L"������ ��ư�� ���� ���� ����, ����� �Ͻʽÿ�.";
}

void GuideText::render(HDC mainDC, HINSTANCE hIns)
{
	SetTextAlign(mainDC, TA_CENTER);
	TextOut(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, _text, 27);
}
