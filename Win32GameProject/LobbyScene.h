#pragma once
#include "Scene.h"
#include "GameObject.h"
#include "Tile.h"
#include "ResetTile.h"
#include "UI.h"
#include "Timer.h"
#include "BackGround.h"
#include "BackButton.h"

class Scene;

class LobbyScene : public Scene
{
public:
    int dx[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };
    int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
    

    LobbyScene();
    virtual ~LobbyScene();
    
    virtual void start();
    virtual void end();

    static LobbyScene* GetInstance();
    static void DestroyInstance();

    void MapInit();
    char* convertnum(int num);
    void OpenMap(int x, int y);
    void OpenBlank(int x, int y);
    void SetMineCount(int count) { _MineCount = count; }
    bool isPlaying() { return _isPlaying; }
    int GetMineCount() { return _MineCount; }
    const int GetMineState(int x, int y) { return _MineMap[y][x]; }
    const bool GetOpenState(int x, int y) { return _isMapOpen[y][x]; }
    void SetOpenState(int x, int y, bool state) { _isMapOpen[y][x] = state; }
    void OpenMines(int select_x, int select_y);
    void GameOver();
    void ResetMap();
    bool check();
    void GameWin();
    int GetCurTime() { return _playTime; }
    void SetCurTime(int num) { _playTime = num; }
    void ResetTimer() { _playTime = 0; }

private:
    static LobbyScene* instance;
    bool _isPlaying = false;
    int _MineMap[20][30];
    bool _isMapOpen[20][30];
    int _MineCount = 99;
    int _defaultMineCount = 99;

    int _playTime = 0;
    
};

