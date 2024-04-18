#include "Timer.h"
#include <iostream>
#include "LobbyScene.h"

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
	char str[20];
	sprintf_s(str, "%01d : %01d", LobbyScene::GetInstance()->GetCurTime() / 60, LobbyScene::GetInstance()->GetCurTime() % 60);
	size_t tmp;
	int len = strlen(str);
	_text = new wchar_t[20];
	mbstowcs_s(&tmp, _text, 20, str, len);
	_textlen = len;
}

void Timer::render(HDC mainDC, HINSTANCE hIns, int x, int y)
{
	SetTextAlign(mainDC, TA_CENTER);
	TextOut(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, _text, _textlen);
}
