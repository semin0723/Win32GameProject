#pragma once
#include "GameObject.h"
class MainBG :
    public GameObject
{
public:
    MainBG();
    ~MainBG();

    virtual void update();
    virtual void render(HDC mainDC, HINSTANCE hIns);

private:
};

