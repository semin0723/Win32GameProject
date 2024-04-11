#pragma once
#include <Windows.h>

namespace time
{
	void InitTime();

	void UpdateTime();

	const float GetFrameRate();

	const ULONGLONG GetDeltaTime();

}