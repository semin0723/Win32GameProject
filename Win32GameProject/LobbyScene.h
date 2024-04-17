#pragma once
#include "Scene.h"
#include "LobbyScene.h"
#include "GameObject.h"
#include "Tile.h"

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
    void OpenMap(int x, int y);
    void OpenBlank(int x, int y);
    const int GetMineState(int x, int y) {
        return _MineMap[y][x];
    }
    const bool GetOpenState(int x, int y) {
        return _isMapOpen[y][x];
    }
    void SetOpenState(int x, int y, bool state) { _isMapOpen[y][x] = state; }
    void GameOver();
    void ResetMap();
    void GameWin();
    
private:
    static LobbyScene* instance;
    int _MineMap[20][30];
    bool _isMapOpen[20][30];
};

