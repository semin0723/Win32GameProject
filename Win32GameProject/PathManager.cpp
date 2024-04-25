#include "PathManager.h"

PathManager* PathManager::instance = nullptr;

PathManager::PathManager() : _ContentPath {}
{
}

PathManager::~PathManager()
{
}

PathManager* PathManager::GetInstance()
{
	if (instance == nullptr) {
		instance = new PathManager;
	}
	return instance;
}

void PathManager::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}

void PathManager::InitPath()
{
	GetCurrentDirectory(255, _ContentPath);

	for (int i = wcslen(_ContentPath) - 1; i >= 0; i--) {
		if (_ContentPath[i] == '\\') {
			_ContentPath[i] = '\0';
			break;
		}
	}
	wcscat_s(_ContentPath, 255, L"\\Main\\data\\image\\");
	SetWindowText(global::GetWinApp().GetWindow(), _ContentPath);
}
