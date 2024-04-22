#include "LobbyScene.h"
#include "queue.hpp"
#include <random>

LobbyScene* LobbyScene::instance = nullptr;

LobbyScene::LobbyScene() {
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			_MineMap[i][j] = 0;
			_isMapOpen[i][j] = 0;
		}
	}
}

LobbyScene::~LobbyScene() {

}

void LobbyScene::start() {
	BackGround* bg = new BackGround;
	bg->SetLocation(Vector3(0, 0, 0));
	bg->SetResourceID((int)MAIN_BACKGROUND);
	Scene::AddGameObject(bg, (int)LAYER_GROUP::BG);
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			Tile* tile = new Tile;
			tile->SetResourceID(UNOPENED_UNFOCUS);
			tile->SetLocation(Vector3((float)(32 + 32 * j), (float)(96 + 32 * i), 0));
			Scene::AddObject(tile, j, i);
		}
	}
	BackButton* bbtn = new BackButton;
	bbtn->SetLocation(Vector3(576, 36, 0));
	bbtn->SetResourceID(BUTTON_BACK);
	bbtn->Setname("Back");
	Scene::AddGameObject(bbtn, (int)LAYER_GROUP::BUTTON);

	ResetTile* tile = new ResetTile;
	tile->SetResourceID(SMILE_FACE);
	tile->SetLocation(Vector3(float(512), float(36), 0));
	tile->Setname("Reset");
	Scene::AddGameObject(tile, (int)LAYER_GROUP::BUTTON);
		
	UI* MineCount = new UI;
	MineCount->SetLocation(Vector3((float)60, (float)44, 0));
	Scene::AddUI(MineCount);

	GuideText* text = new GuideText;
	text->SetLocation(Vector3(300, 44, 0));
	Scene::AddGameObject(text, (int)LAYER_GROUP::UI);

	Timer* timer = new Timer;
	timer->SetLocation(Vector3((float)910, (float)44, 0));
	Scene::AddTimer(timer);
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
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			_MineMap[i][j] = 0;
			_isMapOpen[i][j] = 0;
		}
	}
	int MineCount = _defaultMineCount;
	while (MineCount > 0) {
		int x = GetRandomNum(count_x), y = GetRandomNum(count_y);
		if (_MineMap[y][x] == 0) {
			_MineMap[y][x] = 10;
			MineCount--;
		}
	}
	for (int y = 0; y < count_y; y++) {
		for (int x = 0; x < count_x; x++) {
			if (_MineMap[y][x] == 10) {
				for (int c = 0; c < 8; c++) {
					int nx = x + dx[c], ny = y + dy[c];
					if (nx >= 0 && nx < count_x && ny >= 0 && ny < count_y) {
						if (_MineMap[ny][nx] < 9) {
							_MineMap[ny][nx]++;
						}
					}
				}
			}
		}
	}
}

char* LobbyScene::convertnum(int num) {
	char convert[10];
	sprintf_s(convert, "%d", num);
	return convert;
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
	case 10:
		return UNOPENED_MINE;
	case 11:
		return UNOPENED_UNFOCUS;
	case 12:
		return FLAG_POINT;
	case 13:
		return DIED_FACE;
	case 14:
		return WIN_FACE;
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
			if (ny >= 0 && ny < count_y && nx >= 0 && nx < count_x) {
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

void LobbyScene::OpenMines(int select_x, int select_y) {
	for (int y = 0; y < count_y; y++) {
		for (int x = 0; x < count_x; x++) {
			if (y == select_y && x == select_x) continue;
			if (_MineMap[y][x] == 10) {
				Scene::ChangeObjectState(x, y, GetResourceID(_MineMap[y][x]));
			}
		}
	}
}

void LobbyScene::GameOver()
{
	_isPlaying = false;
	Scene::ChangeResetObjectState("Reset", GetResourceID(13));
}

void LobbyScene::ResetMap()
{
	MapInit();
	ResetTimer();
	for (int y = 0; y < count_y; y++) {
		for (int x = 0; x < count_x; x++) {
			Scene::ChangeObjectState(x, y, GetResourceID(11));
		}
	}
	_isPlaying = true;
	_MineCount = 99;
}

bool LobbyScene::check() {
	int MineFlagCount = 0;
	for (int y = 0; y < count_y; y++) {
		for (int x = 0; x < count_x; x++) {
			if ((Scene::GetObjectState(x, y) == FLAG_POINT) && _MineMap[y][x] == 10) {
				MineFlagCount++;
			}
			if ((Scene::GetObjectState(x, y) == UNOPENED_UNFOCUS)) {
				MineFlagCount++;
			}
		}
	}
	if (MineFlagCount == _defaultMineCount) return true;
	else return false;
}

void LobbyScene::GameWin()
{
	_isPlaying = false;
	for (int y = 0; y < count_y; y++) {
		for (int x = 0; x < count_x; x++) {
			if ((Scene::GetObjectState(x, y) == UNOPENED_UNFOCUS)) {
				Scene::ChangeObjectState(x, y, GetResourceID(12));
			}
		}
	}
	Scene::ChangeResetObjectState("Reset", GetResourceID(14));
}
