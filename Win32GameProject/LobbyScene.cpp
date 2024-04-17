#include "LobbyScene.h"

LobbyScene::LobbyScene() {

}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	Tile* tile = new Tile;
	tile->SetResourceID(UNOPENED);
	Scene::AddObject(tile, LAYER_GROUP::UNOPEN);
	//TODO: 여기서 지뢰의 맵을 구성하고, 각 맵에 해당하는 지뢰 리소스를 넣어야 합니다.
}

void LobbyScene::end() {

}