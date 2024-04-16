#include "InputSystem.h"

InputSystem* InputSystem::instance = nullptr;

InputSystem::InputSystem()
{
	for (int i = 0; i < 256; i++) {
		_isKeyDown[i] = false;
		_isKeyUp[i] = false;
		_isKey[i] = false;
	}
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

void InputSystem::ResetInput() {
	for (int i = 0; i < 256; i++) {
		_isKeyDown[i] = false;
		_isKeyUp[i] = false;
		_isKey[i] = false;
	}
}