#pragma once
#include "GameObject.h"
#include "TimeSystem.h"
#include <string>

class Timer : public GameObject {
public:
	Timer();
	~Timer();

	virtual void update();
	virtual void render(HDC mainDC, HINSTANCE hIns);

private:
	int _textlen;
	std::wstring _text;
	float _elapseTime;
};