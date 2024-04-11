#include "TimeSystem.h"

time* time::instance = nullptr;

time::time() {
	_curTime = _prevTime = GetTickCount64();
	_deltaTime = 0;
}

time* time::GetInstance() {
	if (instance == nullptr) {
		instance = new time();
	}
	return instance;
}

void time::DeleteInstance() {
	delete instance;
	instance = nullptr;
}

void time::UpdateTime() {
	_prevTime = _curTime;
	_curTime = GetTickCount64();
	_deltaTime = _curTime - _prevTime;
}

const ULONGLONG time::GetDeltaTime(){
	return _deltaTime;
}