#pragma once
#include "Vector.hpp"
#include "globalheader.h"
#include "GameObject.h"
#include "Win32GameProject.h"
#include "Tile.h"

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
	void AddObject(Tile* obj, int y) { _Objects[y].push_back(obj); }

private:
	Vector<Tile*> _Objects[20];
	const char* _SceneName;
};