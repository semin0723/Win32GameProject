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
	virtual void render(HDC mainDC);

private:

};