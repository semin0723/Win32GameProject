#include "ResourceManager.h"
#include "PathManager.h"

ResourceManager* ResourceManager::instance = nullptr;
const wchar_t* GetResourcePath(int idx);

ResourceManager::ResourceManager()
{
}

ResourceManager::~ResourceManager()
{
}

ResourceManager* ResourceManager::GetInstance()
{
    if (instance == nullptr) {
        instance = new ResourceManager;
    }
    return instance;
}

void ResourceManager::DestroyInstance()
{
    delete instance;
    instance = nullptr;
}

void ResourceManager::InitTexture()
{
    //TODO: 여기서 모든 이미지 데이터를 갖고와 텍스쳐를 형성해야합니다.
    wchar_t path[255] = {};
    for (int i = 1; wcscmp(GetResourcePath(i), L"") != 0; i++) {
        wcscpy_s(path, 255, PathManager::GetInstance()->GetContentPath());
        wchar_t relative_path[30];
        wcscpy_s(relative_path, GetResourcePath(i));
        wcscat_s(path, 255, relative_path);
        Texture tex;
        for (int l = wcslen(relative_path) - 1; l >= 0; l--) {
            if (relative_path[l] == '.') {
                relative_path[l] = '\0';
                break;
            }
        }
        tex.SetKey(relative_path);
        tex.SetPath(path);
        tex.Load();
        _Textures.push_back(tex);
    }
}

Texture& ResourceManager::GetTexture(const wchar_t* key)
{
	//TODO: Texture안에 있는 strkey를 기반으로 Vector 검색.
    for (int i = 0; i < _Textures.size(); i++) {
        if (wcscmp(key, _Textures[i].GetKey()) == 0) {
            return _Textures[i];
        }
    }
}

const wchar_t* GetResourcePath(int idx) {
    switch (idx) {
    case 1:
        return L"MainMap.bmp";
    case 2:
        return L"Title.bmp";
    case 3:
        return L"Play_Button.bmp";
    case 4:
        return L"Play_Button_Clicked.bmp";
    case 5:
        return L"Smile_Face.bmp";
    case 6:
        return L"Died_Face.bmp";
    case 7:
        return L"Win_Face.bmp";
    case 8:
        return L"Opened_Mine.bmp";
    case 9:
        return L"Mine.bmp";
    case 10:
        return L"Flag.bmp";
    case 11:
        return L"Back_Button.bmp";
    case 12:
        return L"UnOpenedTile.bmp";
    case 13:
        return L"UnOpenedTile_Focus.bmp";
    case 14:
        return L"Opened_One.bmp";
    case 15:
        return L"Opened_Two.bmp";
    case 16:
        return L"Opened_Three.bmp";
    case 17:
        return L"Opened_Four.bmp";
    case 18:
        return L"Opened_Five.bmp";
    case 19:
        return L"Opened_Six.bmp";
    case 20:
        return L"Opened_Seven.bmp";
    case 21:
        return L"Opened_Eight.bmp";
    case 22:
        return L"WhiteBoard.bmp";
    default:
        return L"";
    }
}