#pragma once
#include "PathManager.h"
#include "Texture.h"
#include "Vector.hpp"

class ResourceManager
{
public:
	ResourceManager();
	~ResourceManager();

	static ResourceManager* GetInstance();
	static void DestroyInstance();

	void InitTexture();
	Texture& GetTexture(const wchar_t* key);

private:
	static ResourceManager* instance;
	Vector<Texture> _Textures;
};

