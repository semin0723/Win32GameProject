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
	_Scenes[(int)SCENE_LAYER::MAIN] = LobbyScene::GetInstance();
	_Scenes[(int)SCENE_LAYER::MAIN]->SetSceneName("Lobby");
	_curScene = _Scenes[(int)SCENE_LAYER::MAIN];
	_curScene->start();
}

void SceneManager::update() {
	_curScene->update();
}
void SceneManager::render(HDC mainDC, HINSTANCE hIns) {
	_curScene->render(mainDC, hIns);
}

// TODO: ���� ������ ���� �� ��ȯ ����� �߰��մϴ�.
//		- ���� ȭ�� ���� �����, �ʱ� �߱� ��� ������ ���̵� ����ȭ�� ��ŵ�ϴ�.
//		- ��ư�� ������ �ش� ���̵��� ������ �̵��ϴ� ����� ����ϴ�.