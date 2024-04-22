#pragma once
#include "GameObject.h"

class BackButton :
    public GameObject
{
public:
    BackButton();
    ~BackButton();

    virtual void update();
    virtual void render(HDC mainDC, HINSTANCE hIns);

private:
};

