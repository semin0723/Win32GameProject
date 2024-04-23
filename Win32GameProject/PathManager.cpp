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
	wcscat_s(_ContentPath, 255, L"\\Resource\\Image\\");
	SetWindowText(global::GetWinApp().GetWindow(), _ContentPath);
}
