#pragma once
#include <Windows.h>

class time
{
public:
	time();

	static time* GetInstance();
	static void DeleteInstance();

	void UpdateTime();
	const float GetFrameRate();
	const ULONGLONG GetDeltaTime();

private:
	ULONGLONG _curTime;
	ULONGLONG _prevTime;
	ULONGLONG _deltaTime;

	static time* instance;
};