#include "Tile.h"
#include "LobbyScene.h"

Tile::Tile()
{
}

Tile::~Tile()
{
}

void Tile::update() {
	InputSystem::MouseState curState = InputSystem::GetInstance()->GetMouseState();
	InputSystem::MouseState prevState = InputSystem::GetInstance()->GetPrevMouseState();
	int prev_x = prevState._x / 32, prev_y = prevState._y / 32;
	int cur_x = curState._x / 32, cur_y = curState._y / 32;
	int obj_x = GameObject::GetLocation()._x / 32, obj_y = GameObject::GetLocation()._y / 32;
	int state = LobbyScene::GetInstance()->GetMineState(obj_x - 1, obj_y - 3);
	bool openstate = LobbyScene::GetInstance()->GetOpenState(obj_x - 1, obj_y - 3);
	//TODO: 현재 마우스 위치랑 오브젝트의 위치랑 맞지않아도 눌림처리가 되는 경우가 있습니다. 이를 수정해야합니다.
	if (prev_x >= 1 && cur_x >= 1 && prev_y >= 3 && cur_y >= 3 &&
		prev_x <= 30 && cur_x <= 30 && prev_y <= 22 && cur_y <= 22) {
		if (prev_x == obj_x && cur_x == obj_x && prev_y == obj_y && cur_y == obj_y) {
			if ((prev_x == cur_x && prev_y == cur_y)) {
				if ((prevState._left == 0 && curState._left == 1) || (prevState._left == 1 && curState._left == 1)) {
					if (GameObject::GetResourceID() == UNOPENED_UNFOCUS) {
						GameObject::SetResourceID(UNOPENED_FOCUS);
					}
				}
				else if ((prevState._left == 1 && curState._left == 0)) {
					if (GameObject::GetResourceID() != FLAG_POINT) {
						// TODO: 여기서 지뢰 전체의 맵을 검색하는 로직을 추가해야합니다.
						LobbyScene::GetInstance()->OpenMap(obj_x - 1, obj_y - 3);
						switch (state) {
						case 0:
							GameObject::SetResourceID(UNOPENED_FOCUS);
							break;
						case 1:
							GameObject::SetResourceID(OPENED_ONE);
							break;
						case 2:
							GameObject::SetResourceID(OPENED_TWO);
							break;
						case 3:
							GameObject::SetResourceID(OPENED_THREE);
							break;
						case 4:
							GameObject::SetResourceID(OPENED_FOUR);
							break;
						case 5:
							GameObject::SetResourceID(OPENED_FIVE);
							break;
						case 6:
							GameObject::SetResourceID(OPENED_SIX);
							break;
						case 7:
							GameObject::SetResourceID(OPENED_SEVEN);
							break;
						case 8:
							GameObject::SetResourceID(OPENED_EIGHT);
							break;
						default:
							break;
						}
					}
				}
				else if (prevState._right == 0 && curState._right == 1) {
					if (GameObject::GetResourceID() == UNOPENED_UNFOCUS) {
						GameObject::SetResourceID(FLAG_POINT);
					}
					else if (GameObject::GetResourceID() == FLAG_POINT) {
						GameObject::SetResourceID(UNOPENED_UNFOCUS);
					}
				}
			}
		}
		else {
			if (GameObject::GetResourceID() == UNOPENED_FOCUS && openstate == false) {
				GameObject::SetResourceID(UNOPENED_UNFOCUS);
			}
		}
	}
}

void Tile::render(HDC mainDC, HINSTANCE hIns, int x, int y) {
	HBITMAP MainBitmap, OldBitmap;
	BITMAP myInfo;
	HDC tmp = CreateCompatibleDC(mainDC);
	MainBitmap = LoadBitmap(hIns, MAKEINTRESOURCE(GameObject::GetResourceID()));
	GetObject(MainBitmap, sizeof(BITMAP), (BITMAP*)&myInfo);
	OldBitmap = (HBITMAP)SelectObject(tmp, MainBitmap);

	GameObject::SetLocation( Vector3((float)(32 + myInfo.bmWidth * x), (float)(96 + myInfo.bmHeight * y), 0) );
	BitBlt(mainDC, 32 + myInfo.bmWidth * x, 96 + myInfo.bmHeight * y, myInfo.bmWidth, myInfo.bmHeight, tmp, 0, 0, SRCCOPY);

	SelectObject(tmp, OldBitmap);
	DeleteObject(MainBitmap);
	DeleteDC(tmp);
}