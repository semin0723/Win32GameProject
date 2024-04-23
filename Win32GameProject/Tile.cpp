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
	//TODO: ���� ���콺 ��ġ�� ������Ʈ�� ��ġ�� �����ʾƵ� ����ó���� �Ǵ� ��찡 �ֽ��ϴ�. �̸� �����ؾ��մϴ�.
	if (LobbyScene::GetInstance()->isPlaying() == true) {
		if (prev_x >= 1 && cur_x >= 1 && prev_y >= 3 && cur_y >= 3 &&
			prev_x <= 30 && cur_x <= 30 && prev_y <= 22 && cur_y <= 22) {
			if (prev_x == obj_x && cur_x == obj_x && prev_y == obj_y && cur_y == obj_y) {
				if ((prev_x == cur_x && prev_y == cur_y)) {
					if ((prevState._left == 0 && curState._left == 1) || (prevState._left == 1 && curState._left == 1)) {
						if (GameObject::GetResourceID() == UNOPENED_UNFOCUS) {
							GameObject::SetResourceID(UNOPENED_FOCUS);
							GameObject::SetDirectory("UnOpenedTile_Focus.bmp");
						}
					}
					else if ((prevState._left == 1 && curState._left == 0)) {
						if (GameObject::GetResourceID() != FLAG_POINT) {
							// TODO: ���⼭ ���� ��ü�� ���� �˻��ϴ� ������ �߰��ؾ��մϴ�.
							LobbyScene::GetInstance()->OpenMap(obj_x - 1, obj_y - 3);
							switch (state) {
							case 0:
								GameObject::SetResourceID(UNOPENED_FOCUS);
								GameObject::SetDirectory("UnOpenedTile.bmp");
								break;
							case 1:
								GameObject::SetResourceID(OPENED_ONE);
								GameObject::SetDirectory("Opened_One.bmp");
								break;
							case 2:
								GameObject::SetResourceID(OPENED_TWO);
								GameObject::SetDirectory("Opened_Two.bmp");
								break;
							case 3:
								GameObject::SetResourceID(OPENED_THREE);
								GameObject::SetDirectory("Opened_Three.bmp");
								break;
							case 4:
								GameObject::SetResourceID(OPENED_FOUR);
								GameObject::SetDirectory("Opened_Four.bmp");
								break;
							case 5:
								GameObject::SetResourceID(OPENED_FIVE);
								GameObject::SetDirectory("Opened_Five.bmp");
								break;
							case 6:
								GameObject::SetResourceID(OPENED_SIX);
								GameObject::SetDirectory("Opened_Six.bmp");
								break;
							case 7:
								GameObject::SetResourceID(OPENED_SEVEN);
								GameObject::SetDirectory("Opened_Seven.bmp");
								break;
							case 8:
								GameObject::SetResourceID(OPENED_EIGHT);
								GameObject::SetDirectory("Opened_Eight.bmp");
								break;
							case 10:
								GameObject::SetResourceID(SELECTED_MINE);
								GameObject::SetDirectory("Opened_Mine.bmp");
								LobbyScene::GetInstance()->OpenMines(obj_x - 1, obj_y - 3);
								LobbyScene::GetInstance()->GameOver();
								break;
							default:
								break;
							}
						}
					}
					else if (prevState._right == 0 && curState._right == 1) {
						if (GameObject::GetResourceID() == UNOPENED_UNFOCUS) {
							GameObject::SetResourceID(FLAG_POINT);
							GameObject::SetDirectory("Flag.bmp");
							LobbyScene::GetInstance()->SetMineCount(LobbyScene::GetInstance()->GetMineCount() - 1);
						}
						else if (GameObject::GetResourceID() == FLAG_POINT) {
							GameObject::SetResourceID(UNOPENED_UNFOCUS);
							GameObject::SetDirectory("UnOpenedTile.bmp");
							LobbyScene::GetInstance()->SetMineCount(LobbyScene::GetInstance()->GetMineCount() + 1);
						}
					}
				}
			}
			else {
				if (GameObject::GetResourceID() == UNOPENED_FOCUS && openstate == false) {
					GameObject::SetResourceID(UNOPENED_UNFOCUS);
					GameObject::SetDirectory("UnOpenedTile.bmp");
				}
			}
		}
		if (LobbyScene::GetInstance()->check()) {
			LobbyScene::GetInstance()->GameWin();
		}
	}
}

void Tile::render(HDC mainDC, HINSTANCE hIns) {
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