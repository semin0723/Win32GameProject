#include "Scene.h"

Scene::Scene() {
	_SceneName = "";
}
Scene::~Scene() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j] != nullptr) {
				delete _GameObjects[i][j];
			}
		}
	}
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			if (_Objects[i][j] != nullptr) {
				delete _Objects[i][j];
			}
		}
	}
	for (int i = 0; i < _UIs.size(); i++) {
		delete _UIs[i];
	}
	for (int i = 0; i < _Timers.size(); i++) {
		delete _Timers[i];
	}
}

void Scene::update() {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if(_GameObjects[i][j]->Enable() == true) _GameObjects[i][j]->update();
		}
	}
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			if (_Objects[i][j] == nullptr || _Objects[i][j]->Enable() == false) continue;
			_Objects[i][j]->update();
		}
	}
	for (int i = 0; i < _UIs.size(); i++) {
		if(_UIs[i]->Enable() == true) _UIs[i]->update();
	}
	for (int i = 0; i < _Timers.size(); i++) {
		if (_Timers[i]->Enable() == true) _Timers[i]->update();;
	}
}

void Scene::render(HDC mainDC, HINSTANCE hIns) {
	for (int i = 0; i < (int)LAYER_GROUP::END; i++) {
		for (int j = 0; j < _GameObjects[i].size(); j++) {
			if (_GameObjects[i][j]->Enable() == true) _GameObjects[i][j]->render(mainDC, hIns);
		}
	}
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			if (_Objects[i][j] == nullptr || _Objects[i][j]->Enable() == false) continue;
			_Objects[i][j]->render(mainDC, hIns);
		}
	}
	for (int i = 0; i < _UIs.size(); i++) {
		if (_UIs[i]->Enable() == true) _UIs[i]->render(mainDC, hIns);
	}
	for (int i = 0; i < _Timers.size(); i++) {
		if (_Timers[i]->Enable() == true) _Timers[i]->render(mainDC, hIns);
	}
}

void Scene::ChangeResetObjectState(const char* name, int StateID)
{
	for (int i = 0; i < _GameObjects[(int)LAYER_GROUP::BUTTON].size(); i++) {
		if (strcmp(name, _GameObjects[(int)LAYER_GROUP::BUTTON][i]->GetName()) == 0) {
			_GameObjects[(int)LAYER_GROUP::BUTTON][i]->SetResourceID(StateID);
		}
	}
}