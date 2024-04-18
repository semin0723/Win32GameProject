#include "Scene.h"

Scene::Scene() {
	_SceneName = "";
}
Scene::~Scene() {
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			if (_Objects[i][j] != nullptr) {
				delete _Objects[i][j];
			}
		}
	}
	delete _ResetButton;
	for (int i = 0; i < _UIs.size(); i++) {
		delete _UIs[i];
	}
	for (int i = 0; i < _Timers.size(); i++) {
		delete _Timers[i];
	}
}

void Scene::update() {
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			_Objects[i][j]->update();
		}
	}
	_ResetButton->update();
	for (int i = 0; i < _UIs.size(); i++) {
		_UIs[i]->update();
	}
	for (int i = 0; i < _Timers.size(); i++) {
		_Timers[i]->update();;
	}
}

void Scene::render(HDC mainDC, HINSTANCE hIns) {
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			_Objects[i][j]->render(mainDC, hIns, j, i);
		}
	}
	_ResetButton->render(mainDC, hIns, 0, 0);
	for (int i = 0; i < _UIs.size(); i++) {
		_UIs[i]->render(mainDC, hIns, 0, 0);
	}
	for (int i = 0; i < _Timers.size(); i++) {
		_Timers[i]->render(mainDC, hIns, 0, 0);
	}
}