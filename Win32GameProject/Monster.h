#pragma once

#include "GameObject.h"
// TODO : ���� �⺻ Ŭ���� ����.

class Monster : public GameObject
{
public:
	Monster();
	~Monster();

	void SetHp(const int hp) { _hp = hp; }
	void SetDefence(const int def) { _defence = def; }
	void SetSpeed(const float speed) { _speed = speed; }

	int Gethp() const { return _hp; }
	int Getdefence() const { return _defence; };
	float Getspeed() const { return _speed; }

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);
private:
	int _hp;
	int _defence;
	float _speed;
	
};

/*
	������ Ư¡:
	hp, speed, defence
*/