#pragma once
#include "Vector.hpp"
#include "globalheader.h"

class GameObject;

class Scene {
public:
	Scene();
	~Scene();

	void SetSceneName(const char* name) { _SceneName = name; }
	const char* GetSceneName() const { return _SceneName; }
	void AddObject(GameObject* obj) { _Objects->push_back(obj); }

private:
	Vector<GameObject*> _Objects[(int)LAYER_GROUP::END];
	const char* _SceneName;
};