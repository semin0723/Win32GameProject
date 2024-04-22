#include "ResetTile.h"
#include "LobbyScene.h"

ResetTile::ResetTile()
{
}

ResetTile::~ResetTile()
{
}

void ResetTile::update()
{
	InputSystem::MouseState curState = InputSystem::GetInstance()->GetMouseState();
	InputSystem::MouseState prevState = InputSystem::GetInstance()->GetPrevMouseState();
	int prev_x = prevState._x / 32, prev_y = prevState._y / 32;
	int cur_x = curState._x / 32, cur_y = curState._y / 32;
	int obj_x = GameObject::GetLocation()._x / 32, obj_y = GameObject::GetLocation()._y / 32;
	int state = LobbyScene::GetInstance()->GetMineState(obj_x - 1, obj_y - 3);
	if (prev_x == 16 && cur_x == 16 && prev_y == 1 && cur_y == 1) {
		if (prev_x == obj_x && cur_x == obj_x && prev_y == obj_y && cur_y == obj_y) {
			if ((prev_x == cur_x && prev_y == cur_y)) {
				if ((prevState._left == 1 && curState._left == 0)) { // ÁÂÅ¬¸¯ ¶ÃÀ» ¶§.
					LobbyScene::GetInstance()->ResetMap();
					GameObject::SetResourceID(SMILE_FACE);
				}
			}
		}
	}
}

void ResetTile::render(HDC mainDC, HINSTANCE hIns)
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