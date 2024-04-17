#include "LobbyScene.h"
#include "queue.hpp"
#include <random>

LobbyScene* LobbyScene::instance = nullptr;

LobbyScene::LobbyScene() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			_MineMap[i][j] = 0;
			_isMapOpen[i][j] = 0;
		}
	}
}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			Tile* tile = new Tile;
			tile->SetResourceID(UNOPENED);
			tile->SetLocation(Vector3((float)(32 + 32 * j), (float)(96 + 32 * i), 0));
			Scene::AddObject(tile, j, i);
		}
	}
	//TODO: 여기서 지뢰의 맵을 구성하고, 각 맵에 해당하는 지뢰 리소스를 넣어야 합니다.
	MapInit();
}

void LobbyScene::end() {

}

LobbyScene* LobbyScene::GetInstance()
{
	if (instance == nullptr) {
		instance = new LobbyScene;
	}
	return instance;
}

void LobbyScene::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}

int GetRandomNum(int size) {
	std::random_device rand;
	std::mt19937 gen(rand());
	std::uniform_int_distribution<int> dis(0, size - 1);

	return dis(gen);
}

void LobbyScene::MapInit() {
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 30; j++) {
			_MineMap[i][j] = 0;
			_isMapOpen[i][j] = 0;
		}
	}
	int MineCount = 99;
	while (MineCount > 0) {
		int x = GetRandomNum(30), y = GetRandomNum(20);
		if (_MineMap[y][x] == 0) {
			_MineMap[y][x] = 10;
			MineCount--;
		}
	}
	for (int y = 0; y < 20; y++) {
		for (int x = 0; x < 30; x++) {
			if (_MineMap[y][x] == 10) {
				for (int c = 0; c < 8; c++) {
					int nx = x + dx[c], ny = y + dy[c];
					if (nx >= 0 && nx < 30 && ny >= 0 && ny < 20) {
						if (_MineMap[ny][nx] < 9) {
							_MineMap[ny][nx]++;
						}
					}
				}
			}
		}
	}
}

int GetResourceID(int state) {
	switch (state) {
	case 0:
		return UNOPENED_FOCUS;
	case 1:
		return OPENED_ONE;
	case 2:
		return OPENED_TWO;
	case 3:
		return OPENED_THREE;
	case 4:
		return OPENED_FOUR;
	case 5:
		return OPENED_FIVE;
	case 6:
		return OPENED_SIX;
	case 7:
		return OPENED_SEVEN;
	case 8:
		return OPENED_EIGHT;
	}
}

void LobbyScene::OpenBlank(int x, int y) {
	COORD pos = { x, y };
	queue<COORD> save;
	save.push(pos);
	while (!save.empty()) {
		const int cy = save.front().Y, cx = save.front().X;
		save.pop();
		for (int k = 0; k < 8; k++) {
			int ny = cy + dy[k], nx = cx + dx[k];
			if (ny >= 0 && ny < 20 && nx >= 0 && nx < 30) {
				if (_MineMap[ny][nx] < 9 && _isMapOpen[ny][nx] == false) {
					_isMapOpen[ny][nx] = 1;
					Scene::ChangeObjectState(nx, ny, GetResourceID(_MineMap[ny][nx]));
					if (_MineMap[ny][nx] == 0) {
						COORD npos = { nx, ny };
						save.push(npos);
					}
				}
			}
		}
	}
}

void LobbyScene::OpenMap(int x, int y) {
	_isMapOpen[y][x] = true;
	if (_MineMap[y][x] == 0) {
		OpenBlank(x, y);
	}
}

void LobbyScene::GameOver()
{
	
}

void LobbyScene::ResetMap()
{
	MapInit();
}

void LobbyScene::GameWin()
{

}
