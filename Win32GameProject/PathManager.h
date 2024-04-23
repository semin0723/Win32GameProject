#pragma once
#include "Win32GameProject.h"

class PathManager
{
public:
	PathManager();
	~PathManager();

	static PathManager* GetInstance();
	static void DestroyInstance();

	void InitPath();
	wchar_t* GetContentPath() { return _ContentPath; }

private:
	static PathManager* instance;
	wchar_t _ContentPath[256];
};

