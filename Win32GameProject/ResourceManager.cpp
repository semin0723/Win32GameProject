#include "ResourceManager.h"

ResourceManager* ResourceManager::instance = nullptr;

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

const char* ResourceManager::GetResourceName(int state) {
	switch (state) {
	case 0:
		return "UnOpenedTile_Focus";
	case 1:
		return "Opened_One";
	case 2:
		return "Opened_Two";
	case 3:
		return "Opened_Three";
	case 4:
		return "Opened_Four";
	case 5:
		return "Opened_Five";
	case 6:
		return "Opened_Six";
	case 7:
		return "Opened_Seven";
	case 8:
		return "Opened_Eight";
	case 10:
		return "Mine";
	case 11:
		return "UnOpenedTile";
	case 12:
		return "Flag";
	case 13:
		return "Died_Face";
	case 14:
		return "Win_Face";
	case 15:
		return "UnOpenedTile";
	case 16:
		return "Play_Button";
	case 17:
		return "Play_Button_Clicked";
	case 18:
		return "Smile_Face";
	}
}

//const wchar_t* ResourceManager::GetResourceFilePath(int state)
//{
//	const wchar_t* ResourcePath;
//	switch (state) {
//	case 0:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"UnOpenedTile_Focus.bmp");
//		break;
//	case 1:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_One.bmp");
//		break;
//	case 2:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Two.bmp");
//		break;
//	case 3:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Three.bmp");
//		break;
//	case 4:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Four.bmp");
//		break;
//	case 5:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Five.bmp");
//		break;
//	case 6:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Six.bmp");
//		break;
//	case 7:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Seven.bmp");
//		break;
//	case 8:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Opened_Eight.bmp");
//		break;
//	case 10:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Mine.bmp");
//		break;
//	case 11:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"UnOpenedTile.bmp");
//		break;
//	case 12:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Flag.bmp");
//		break;
//	case 13:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Died_Face.bmp");
//		break;
//	case 14:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Win_Face.bmp");
//		break;
//	case 15:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"UnOpenedTile.bmp");
//		break;
//	case 16:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Play_Button.bmp");
//		break;
//	case 17:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Play_Button_Clicked.bmp");
//		break;
//	case 18:
//		ResourcePath = PathManager::GetInstance()->GetImagePath(L"Smile_Face.bmp");
//		break;
//	default:
//		ResourcePath = L"";
//	}
//
//	return ResourcePath;
//}
