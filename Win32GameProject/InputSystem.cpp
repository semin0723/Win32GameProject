#include "InputSystem.h"

InputSystem* InputSystem::instance = nullptr;

InputSystem::InputSystem()
{
	for (int i = 0; i < 256; i++) {
		_isKeyDown[i] = false;
		_isKeyUp[i] = false;
		_isKey[i] = false;
	}
	InitMouse();
}

InputSystem::~InputSystem()
{
	delete[] _isKeyDown;
	delete[] _isKeyUp;
	delete[] _isKey;
}

InputSystem* InputSystem::GetInstance()
{
	if (instance == nullptr) {
		instance = new InputSystem;
	}
	return instance;
}

void InputSystem::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}

void InputSystem::KeyDown(const unsigned int key)
{
	_isKeyDown[key] = true;
	_isKeyUp[key] = false;
	_isKey[key] = true;
}

void InputSystem::KeyUp(const unsigned int key)
{
	_isKeyDown[key] = false;
	_isKeyUp[key] = true;
	_isKey[key] = false;
}

void InputSystem::InitMouse()
{
	_curMouse._x = global::GetWinApp().GetWidth() / 2;
	_curMouse._y = global::GetWinApp().GetHeight() / 2;
	_curMouse._left = false;
	_curMouse._right = false;
	_curMouse._middle = false;

	_prevMouse = _curMouse;
	SetCursorPos(_curMouse._x, _curMouse._y);
}

void InputSystem::updateMouse()
{
	_prevMouse = _curMouse;

	POINT pos;
	GetCursorPos(&pos);
	ScreenToClient(global::GetWinApp().GetWindow(), &pos);

	_curMouse._x = pos.x;
	_curMouse._y = pos.y;
	_curMouse._wheel = 0;
			  
	_curMouse._left = (GetKeyState(VK_LBUTTON) & 0x8000) != 0;
	_curMouse._right = (GetKeyState(VK_RBUTTON) & 0x8000) != 0;
	_curMouse._middle = (GetKeyState(VK_MBUTTON) & 0x8000) != 0;
}

void InputSystem::ResetInput() {
	for (int i = 0; i < 256; i++) {
		_isKeyDown[i] = false;
		_isKeyUp[i] = false;
		_isKey[i] = false;
	}
}