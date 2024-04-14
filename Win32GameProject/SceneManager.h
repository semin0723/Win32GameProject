#pragma once
#include "globalheader.h"
#include "LobbyScene.h"
#include "Win32GameProject.h"

class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager* GetInstance();
	void DestroyInstance();
	void InitScene();
	void update();
	void render(HDC mainDC);

private:
	static SceneManager* instance;
	Scene* _Scenes[(int)SCENE_LAYER::END];
	Scene* _curScene;
};

