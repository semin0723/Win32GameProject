#include "ButtonStart.h"
#include "MainMenu.h"
#include "SceneManager.h"

ButtonStart::ButtonStart()
{
}

ButtonStart::~ButtonStart()
{
}

void ButtonStart::update()
{
	InputSystem::MouseState curState = InputSystem::GetInstance()->GetMouseState();
	InputSystem::MouseState prevState = InputSystem::GetInstance()->GetPrevMouseState();
	int prev_x = prevState._x, prev_y = prevState._y;
	int cur_x = curState._x, cur_y = curState._y;
	int obj_x = GameObject::GetLocation()._x / 32, obj_y = GameObject::GetLocation()._y / 32;
	if (prev_x >= 432 && cur_x >= 432 && prev_y >= 480 && cur_y >= 480 &&
		prev_x <= 592 && cur_x <= 592 && prev_y <= 544 && cur_y <= 544) {
		if ((prevState._left == 0 && curState._left == 1) || (prevState._left == 1 && curState._left == 1)) {
			if (wcscmp(GameObject::GetDirectory(), L"Play_Button.bmp") == 0) {
				GameObject::SetDirectory("Play_Button_Clicked.bmp");
			}
		}
		else if ((prevState._left == 1 && curState._left == 0)) {
			SceneManager::GetInstance()->LoadScene((int)SCENE_LAYER::PLAY);
		}
	}
	else {
		GameObject::SetDirectory("Play_Button.bmp");
	}
}

void ButtonStart::render(HDC mainDC, HINSTANCE hIns)
{
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = (HBITMAP)LoadImage(NULL, GameObject::GetDirectory(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);

	BitBlt(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);

	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}
