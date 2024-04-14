#pragma once
#include "Scene.h"
#include "LobbyScene.h"
#include "GameObject.h"

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

