#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;
SceneManager::SceneManager() : _curScene(nullptr) {}
SceneManager::~SceneManager() {}

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

}