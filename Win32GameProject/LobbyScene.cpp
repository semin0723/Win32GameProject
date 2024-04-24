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
	wchar_t FilePath[256] = L"";
	wcscat_s(FilePath, 255, PathManager::GetInstance()->GetContentPath());

	BackGround* bg = new BackGround;
	bg->SetLocation(Vector3(0, 0, 0));
	bg->SetDirectory("MainMap.bmp");
	Scene::AddGameObject(bg, (int)LAYER_GROUP::BG);
	for (int i = 0; i < count_y; i++) {
		for (int j = 0; j < count_x; j++) {
			Tile* tile = new Tile;
			tile->SetDirectory("UnOpenedTile.bmp");
			tile->SetLocation(Vector3((float)(32 + 32 * j), (float)(96 + 32 * i), 0));
			Scene::AddObject(tile, j, i);
		}
	}
	BackButton* bbtn = new BackButton;
	bbtn->SetLocation(Vector3(576, 36, 0));
	bbtn->SetDirectory("Back_Button.bmp");
	bbtn->Setname("Back");
	Scene::AddGameObject(bbtn, (int)LAYER_GROUP::BUTTON);

	ResetTile* tile = new ResetTile;
	tile->SetDirectory("Smile_Face.bmp");
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
	_playTime = 0;
	_isPlaying = false;
}

void LobbyScene::end() {
	ResetMap();
	_isPlaying = false;

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

const char* GetResourceID(int state) {
	switch (state) {
	case 0:
		return "UnOpenedTile_Focus.bmp";
	case 1:
		return "Opened_One.bmp";
	case 2:
		return "Opened_Two.bmp";
	case 3:
		return "Opened_Three.bmp";
	case 4:
		return "Opened_Four.bmp";
	case 5:
		return "Opened_Five.bmp";
	case 6:
		return "Opened_Six.bmp";
	case 7:
		return "Opened_Seven.bmp";
	case 8:
		return "Opened_Eight.bmp";
	case 10:
		return "Mine.bmp";
	case 11:
		return "UnOpenedTile.bmp";
	case 12:
		return "Flag.bmp";
	case 13:
		return "Died_Face.bmp";
	case 14:
		return "Win_Face.bmp";
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
			if (wcscmp(Scene::GetObjectState(x, y), L"Flag.bmp") == 0 && _MineMap[y][x] == 10) {
				MineFlagCount++;
			}
			if (wcscmp(Scene::GetObjectState(x, y), L"UnOpenedTile") == 0) {
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
			if (wcscmp(Scene::GetObjectState(x, y), L"UnOpenedTile") == 0) {
				Scene::ChangeObjectState(x, y, GetResourceID(12));
			}
		}
	}
	Scene::ChangeResetObjectState("Reset", GetResourceID(14));
}
