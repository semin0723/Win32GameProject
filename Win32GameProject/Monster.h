#pragma once

#include "GameObject.h"
// TODO : ���� �⺻ Ŭ���� ����.

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
	������ Ư¡:
	hp, speed, defence
*/