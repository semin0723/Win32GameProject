#pragma once
#include "GameObject.h"
class GuideText :
    public GameObject
{
public:
    GuideText();
    ~GuideText();

    virtual void update();
    virtual void render(HDC mainDC, HINSTANCE hIns);

private:
    const wchar_t* _text;
    int _textlen;
};

