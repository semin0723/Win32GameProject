#pragma once

#include "GameObject.h"
#include "RenderSystem.h"
// TODO: UI �⺻ Ŭ���� ����

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

// TODO: UI �ؽ�Ʈ�� ��Ʈ ����� Ű���, �� ��ư�� ���� ���� ������ �߰��մϴ�.