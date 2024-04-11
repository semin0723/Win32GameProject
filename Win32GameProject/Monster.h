#pragma once

#include "GameObject.h"
// TODO : 몬스터 기본 클래스 생성.

class Monster : public GameObject
{
public:
	Monster();

private:
	int _hp;
	int _defence;
	float _speed;
	
};

/*
	몬스터의 특징:
	hp, speed, defence
*/