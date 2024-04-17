#pragma once

#include "GameObject.h"
// TODO : 몬스터 기본 클래스 생성.

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
	몬스터의 특징:
	hp, speed, defence
*/