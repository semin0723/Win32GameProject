#include "LobbyScene.h"

LobbyScene::LobbyScene() {

}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	Monster* monster = new Monster;
	monster->SetLocation(Vector3(48, 112, 0));
	monster->SetResourceID(UNOPENED);
	monster->SetSpeed(20.f);
	Scene::AddObject(monster, LAYER_GROUP::MONSTER);
}

void LobbyScene::end() {

}