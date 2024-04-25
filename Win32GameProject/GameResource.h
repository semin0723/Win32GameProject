#pragma once
#include <iostream>

class GameResource
{
public:
	GameResource();
	~GameResource();

	const wchar_t* GetKey() { return _key; }
	const wchar_t* GetPath() { return _path; }

	void SetKey(const wchar_t* key) { wcscpy_s(_key, key); }
	void SetPath(const wchar_t* path) { wcscpy_s(_path, path); }

private:
	wchar_t _key[30];
	wchar_t _path[255];
};

