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
	void GetImagePath(wchar_t* pathname, const wchar_t* ImageFile) { 
		wchar_t tmp[256] = L"";
		wcscat_s(tmp, _ContentPath);
		wcscat_s(tmp, ImageFile);
		wcscpy_s(pathname, wcslen(tmp), tmp);
	}

private:
	static PathManager* instance;
	wchar_t _ContentPath[256];
};

