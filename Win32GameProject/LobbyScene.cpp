#include "LobbyScene.h"

LobbyScene::LobbyScene() {

}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	Tile* tile = new Tile;
	tile->SetResourceID(UNOPENED);
	Scene::AddObject(tile, LAYER_GROUP::UNOPEN);
	//TODO: ���⼭ ������ ���� �����ϰ�, �� �ʿ� �ش��ϴ� ���� ���ҽ��� �־�� �մϴ�.
}

void LobbyScene::end() {

}