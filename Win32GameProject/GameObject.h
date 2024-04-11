#pragma once
#include "Vector3.h"

class GameObject
{
public:
	Vector3 _location;
	int _ResourceID;
	GameObject();
};

/*
	게임오브젝트가 공통적으로 가지고 있는 특성 : 
	스프라이트 ID, 위치

*/