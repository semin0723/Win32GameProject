#pragma once
#include <Windows.h>

class TimeManager
{
public:
	TimeManager();

	static TimeManager* GetInstance();
	static void DestroyInstance();

	void UpdateTime();
	const float GetFrameRate();
	const float GetDeltaTime();

private:
	ULONGLONG _curTime;
	ULONGLONG _prevTime;
	ULONGLONG _deltaTime;

	static TimeManager* instance;
};