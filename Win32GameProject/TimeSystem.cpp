#include "TimeSystem.h"

TimeManager* TimeManager::instance = nullptr;

TimeManager::TimeManager() {
	_curTime = _prevTime = GetTickCount64();
	_deltaTime = 0;
}

TimeManager* TimeManager::GetInstance() {
	if (instance == nullptr) {
		instance = new TimeManager();
	}
	return instance;
}

void TimeManager::DestroyInstance() {
	delete instance;
	instance = nullptr;
}

void TimeManager::UpdateTime() {
	_prevTime = _curTime;
	_curTime = GetTickCount64();
	_deltaTime = _curTime - _prevTime;
}

const float TimeManager::GetDeltaTime(){
	return (float)(_deltaTime / 1000.f);
}