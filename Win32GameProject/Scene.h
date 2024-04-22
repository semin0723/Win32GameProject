#pragma once
#include "Vector.hpp"
#include "globalheader.h"
#include "GameObject.h"
#include "Win32GameProject.h"
#include "Tile.h"
#include "ResetTile.h"
#include "UI.h"
#include "Timer.h"
#include "BackGround.h"

class Tile;

class Scene {
public:
	int count_x = 30, count_y = 20;

	Scene();
	virtual ~Scene();

	void SetSceneName(const char* name) { _SceneName = name; }
	const char* GetSceneName() const { return _SceneName; }
	virtual void start() = 0;
	virtual void end() = 0;
	void update();
	void render(HDC mainDC, HINSTANCE hIns);

protected:
	void AddObject(Tile* obj, int x, int y) { _Objects[y][x] = obj; }
	void AddGameObject(GameObject* obj, int layerid) { _GameObjects[layerid].push_back(obj); }
	void AddUI(UI* obj) { _UIs.push_back(obj); }
	void AddTimer(Timer* obj) { _Timers.push_back(obj); }

	void ChangeObjectState(int x, int y, int StateID) { _Objects[y][x]->SetResourceID(StateID); }
	void ChangeResetObjectState(const char* name, int StateID);

	int GetObjectState(int x, int y) { return _Objects[y][x]->GetResourceID(); }

private:
	Tile* _Objects[20][30];
	Vector<GameObject*> _GameObjects[(int)LAYER_GROUP::END];
	Vector<UI*> _UIs;
	Vector<Timer*> _Timers;
	const char* _SceneName;
};