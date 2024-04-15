#include "LobbyScene.h"

LobbyScene::LobbyScene() {

}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	Monster* monster = new Monster;
	monster->SetLocation(Vector3(100, 100, 0));
	monster->SetResourceID(IDB_BITMAP1);
	monster->SetSpeed(20.f);
	Scene::AddObject(monster, LAYER_GROUP::MONSTER);
}

void LobbyScene::end() {

}