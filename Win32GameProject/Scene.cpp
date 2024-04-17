#include "Scene.h"

Scene::Scene() {
	_SceneName = "";
}
Scene::~Scene() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < /*_Objects[i].size();*/30; j++) {
			if (_Objects[i][j] != nullptr) {
				delete _Objects[i][j];
			}
		}
	}
}

void Scene::update() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			_Objects[i][j]->update();
		}
	}
}

void Scene::render(HDC mainDC, HINSTANCE hIns) {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			_Objects[i][j]->render(mainDC, hIns, j, i);
		}
	}
}