#pragma once
#include "GameObject.h"
#include "TimeSystem.h"

class Timer : public GameObject {
public:
	Timer();
	~Timer();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);

private:
	int _textlen;
	wchar_t* _text;
	float _elapseTime;
};