#pragma once

#include "GameObject.h"
// TODO : ���� �⺻ Ŭ���� ����.

class Tile : public GameObject
{
public:
	Tile();
	~Tile();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);
private:
	
};

/*
	������ Ư¡:
	hp, speed, defence
*/