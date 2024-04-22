#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;
SceneManager::SceneManager() : _curScene(nullptr) {
	for (int i = 0; i < (int)SCENE_LAYER::END; i++) {
		_Scenes[i] = nullptr;
	}
}
SceneManager::~SceneManager() {
	for (int i = 0; i < (int)SCENE_LAYER::END; i++) {
		if (_Scenes[i] != nullptr) {
			delete _Scenes[i];
			_Scenes[i] = nullptr;
		}
	}
}

SceneManager* SceneManager::GetInstance() {
	if(instance == nullptr) {
		instance = new SceneManager;
	}
	return instance;
}

void SceneManager::DestroyInstance() {
	delete instance;
	instance = nullptr;
}

void SceneManager::InitScene() {
	_Scenes[(int)SCENE_LAYER::MAIN] = MainMenu::GetInstance();
	_Scenes[(int)SCENE_LAYER::MAIN]->SetSceneName("Main");
	_Scenes[(int)SCENE_LAYER::PLAY] = LobbyScene::GetInstance();
	_Scenes[(int)SCENE_LAYER::PLAY]->SetSceneName("Lobby");
	
	_curScene = _Scenes[(int)SCENE_LAYER::MAIN];
	_curScene->start();
}

void SceneManager::update() {
	_curScene->update();
}
void SceneManager::render(HDC mainDC, HINSTANCE hIns) {
	_curScene->render(mainDC, hIns);
}

void SceneManager::LoadScene(int idx)
{
	 _curScene = _Scenes[idx];
	 _curScene->start();
}

// TODO: 씬을 여러개 만들어서 씬 전환 기능을 추가합니다.
//		- 메인 화면 씬을 만들고, 초급 중급 고급 순으로 난이도 세분화를 시킵니다.
//		- 버튼을 누르면 해당 난이도의 씬으로 이동하는 기능을 만듭니다.