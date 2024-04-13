#include "GameObject.h"

GameObject::GameObject() {
	Vector3 _location(0.f, 0.f, 0.f);
	Vector3 _scale(0.f, 0.f, 0.f);
	_ResourceID = 0;
}
GameObject::~GameObject() {}
void GameObject::render(HDC hdc) {}