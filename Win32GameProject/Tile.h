#pragma once

#include "GameObject.h"

// TODO : ���� �⺻ Ŭ���� ����.

class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns, int x, int y);
private:
	
};