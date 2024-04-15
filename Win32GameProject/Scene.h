#pragma once
#include "Vector.hpp"
#include "globalheader.h"
#include "GameObject.h"
#include "Win32GameProject.h"

class GameObject;

class Scene {
public:
	Scene();
	virtual ~Scene();

	void SetSceneName(const char* name) { _SceneName = name; }
	const char* GetSceneName() const { return _SceneName; }
	virtual void start() = 0;
	virtual void end() = 0;
	void update();
	void render(HDC mainDC, HINSTANCE hIns);

protected:
	void AddObject(GameObject* obj, LAYER_GROUP group) { _Objects[(int)group].push_back(obj); }

private:
	Vector<GameObject*> _Objects[(int)LAYER_GROUP::END];
	const char* _SceneName;
};