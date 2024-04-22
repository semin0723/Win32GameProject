#include "BackButton.h"
#include "SceneManager.h"

BackButton::BackButton()
{
}

BackButton::~BackButton()
{
}

void BackButton::update()
{
	InputSystem::MouseState curState = InputSystem::GetInstance()->GetMouseState();
	InputSystem::MouseState prevState = InputSystem::GetInstance()->GetPrevMouseState();
	int prev_x = prevState._x, prev_y = prevState._y;
	int cur_x = curState._x, cur_y = curState._y;
	if (prev_x >= 576 && cur_x >= 576 && prev_y >= 36 && cur_y >= 36 &&
		prev_x <= 608 && cur_x <= 608 && prev_y <= 68 && cur_y <= 68) {
		if ((prevState._left == 0 && curState._left == 1) || (prevState._left == 1 && curState._left == 1)) {

		}
		else if ((prevState._left == 1 && curState._left == 0)) {
			SceneManager::GetInstance()->LoadScene((int)SCENE_LAYER::MAIN);
		}
	}
}

void BackButton::render(HDC mainDC, HINSTANCE hIns)
{
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = LoadBitmap(hIns, MAKEINTRESOURCE(GameObject::GetResourceID()));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);

	BitBlt(mainDC, GameObject::GetLocation()._x, GameObject::GetLocation()._y, myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);

	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}
