#pragma once
#include "PathManager.h"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* GetInstance();
	static void DestroyInstance();

	const char* GetResourceName(int state);

	const wchar_t* GetResourceFilePath(int state);

private:
	static ResourceManager* instance;
};

