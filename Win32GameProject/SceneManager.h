#pragma once
#include "globalheader.h"
#include "LobbyScene.h"

class Scene;

class SceneManager
{
public:
	SceneManager();
	~SceneManager();

	static SceneManager* GetInstance();
	void DestroyInstance();
	void InitScene();

private:
	static SceneManager* instance;
	Scene* _Scenes[(int)SCENE_LAYER::END];
	Scene* _curScene;
};

