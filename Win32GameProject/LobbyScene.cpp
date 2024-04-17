#include "LobbyScene.h"
#include "queue.hpp"
#include <random>

LobbyScene::LobbyScene() {

}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			Tile* tile = new Tile;
			tile->SetResourceID(UNOPENED);
			Scene::AddObject(tile, i);
		}
	}
	//TODO: 여기서 지뢰의 맵을 구성하고, 각 맵에 해당하는 지뢰 리소스를 넣어야 합니다.
}

void LobbyScene::end() {

}

int GetRandomNum(int size) {
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<int> dis(0, size - 1);

	return dis(gen);
}

void MapInit() {
	int MineCount = 99;
	while (MineCount > 0) {
		int x = GetRandomNum(30), y = GetRandomNum(20);

	}
}

void MakeMineMap() {

}