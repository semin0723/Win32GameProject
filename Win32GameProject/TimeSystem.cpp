#include "TimeSystem.h"

namespace time {

	ULONGLONG curTime;
	ULONGLONG prevTime;
	ULONGLONG deltaTime;

	void InitTime() {
		curTime = prevTime = GetTickCount64();
	}

	void UpdateTime() {
		prevTime = curTime;
		curTime = GetTickCount64();
		deltaTime = curTime - prevTime;
	}

	const float GetFrameRate();

	const ULONGLONG GetDeltaTime() {
		return deltaTime;
	}
}