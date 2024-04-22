#pragma once
#include "GameObject.h"

class Title : public GameObject {
public:
	Title();
	~Title();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);

private:
};