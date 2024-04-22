#pragma once
#include "GameObject.h"

class ResetTile : public GameObject {
public:
	ResetTile();
	~ResetTile();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);
};
