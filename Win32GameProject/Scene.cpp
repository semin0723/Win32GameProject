#include "Scene.h"

Scene::Scene() {
	_SceneName = "";
}
Scene::~Scene() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _Objects[i].size(); j++) {
			delete _Objects[i][j];
		}
	}
}

void Scene::update() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _Objects[i].size(); j++) {
			_Objects[i][j]->update();
		}
	}
}

void Scene::render(HDC mainDC, HINSTANCE hIns) {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _Objects[i].size(); j++) {
			_Objects[i][j]->render(mainDC, hIns);
		}
	}
}