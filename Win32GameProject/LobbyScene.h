#pragma once
#include "Scene.h"
#include "LobbyScene.h"
#include "GameObject.h"
#include "Tile.h"

class LobbyScene :
    public Scene
{
public:
    LobbyScene();
    virtual ~LobbyScene();
    
    virtual void start();
    virtual void end();

private:

};

