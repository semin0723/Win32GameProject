#pragma once
#include "GameObject.h"

class ButtonStart : public GameObject {
public:
	ButtonStart();
	~ButtonStart();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);

private:
};