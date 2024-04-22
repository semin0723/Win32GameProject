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

// TODO: ���� ������ ���� �� ��ȯ ����� �߰��մϴ�.
//		- ���� ȭ�� ���� �����, �ʱ� �߱� ��� ������ ���̵� ����ȭ�� ��ŵ�ϴ�.
//		- ��ư�� ������ �ش� ���̵��� ������ �̵��ϴ� ����� ����ϴ�.