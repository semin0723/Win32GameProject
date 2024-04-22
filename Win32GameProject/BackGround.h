#pragma once
#include "GameObject.h"
class BackGround :
    public GameObject
{
public:
    BackGround();
    ~BackGround();

    virtual void update();
    virtual void render(HDC mainDC, HINSTANCE hIns);

private:


};

