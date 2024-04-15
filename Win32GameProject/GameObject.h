#pragma once
#include "Vector3.h"
#include "Win32GameProject.h"
#include "TimeSystem.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	void SetLocation(const Vector3& loc) { _location = loc; }
	void SetResourceID(const int id) { _ResourceID = id; }
	void SetScale(const Vector3& scale) { _scale = scale; }

	Vector3 GetLocation() const { return Vector3(_location); }
	Vector3 GetScale() const { return Vector3(_scale); }
	int GetResourceID() const { return _ResourceID; }

	virtual void update() = 0;
	virtual void render(HDC hdc, HINSTANCE hIns) = 0;

private:
	Vector3 _location;
	Vector3 _scale;
	int _ResourceID;
};

/*
	게임오브젝트가 공통적으로 가지고 있는 특성 : 
	스프라이트 ID, 위치

*/