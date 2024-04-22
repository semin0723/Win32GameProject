#pragma once
#include "Vector3.h"
#include "Win32GameProject.h"
#include "TimeSystem.h"
#include "InputSystem.h"

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();
	void SetLocation(const Vector3& loc) { _location = loc; }
	void SetResourceID(const int id) { _ResourceID = id; }
	void SetScale(const Vector3& scale) { _scale = scale; }
	void Setname(const char* name) { strcpy_s(_name, name); }
	void SetEnable(bool state) { _Enable = state; }

	Vector3 GetLocation() const { return Vector3(_location); }
	Vector3 GetScale() const { return Vector3(_scale); }
	int GetResourceID() const { return _ResourceID; }
	const char* GetName() const { return _name; }
	bool Enable() { return _Enable; }

	virtual void update() = 0;
	virtual void render(HDC hdc, HINSTANCE hIns) = 0;

private:
	Vector3 _location;
	Vector3 _scale;
	int _ResourceID;
	char _name[100];
	bool _Enable = true;
};

/*
	���ӿ�����Ʈ�� ���������� ������ �ִ� Ư�� : 
	��������Ʈ ID, ��ġ

*/