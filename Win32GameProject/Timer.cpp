#include "Timer.h"
#include <iostream>
#include "LobbyScene.h"
#include <string>

Timer::Timer()
{
	_textlen = 0;
	_elapseTime = 0.f;
}

Timer::~Timer()
{
}

void Timer::update()
{
	if (LobbyScene::GetInstance()->isPlaying() == true) {
		_elapseTime += TimeManager::GetInstance()->GetDeltaTime();
		if (_elapseTime >= 1.f) {
			LobbyScene::GetInstance()->SetCurTime(LobbyScene::GetInstance()->GetCurTime() + 1);
			_elapseTime -= 1.f;
		}	
	}

	std::wstring curMin = std::to_wstring(LobbyScene::GetInstance()->GetCurTime() / 60);
	std::wstring curSec = std::to_wstring(LobbyScene::GetInstance()->GetCurTime() % 60);
	_text = curMin + L" : " + curSec;
}

void Timer::render(HDC mainDC, HINSTANCE hIns)
{
	SetBkMode(mainDC, TRANSPARENT);
	SetTextAlign(mainDC, TA_CENTER);
	TextOut(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, _text.c_str(), _text.length());
}
