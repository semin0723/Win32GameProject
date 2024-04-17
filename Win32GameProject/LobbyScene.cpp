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
	//TODO: ���⼭ ������ ���� �����ϰ�, �� �ʿ� �ش��ϴ� ���� ���ҽ��� �־�� �մϴ�.
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