#pragma once

class InputSystem
{
public:
	InputSystem();
	~InputSystem();

	InputSystem* GetInstance();
	void DestroyInstance();

	void KeyDown(const unsigned int key);
	void KeyUp(const unsigned int key);
	bool isKeyDown(const unsigned int key) const { return _isKeyDown[key]; }
	bool isKeyUp(const unsigned int key) const { return _isKeyUp[key]; }
	bool isKey(const unsigned int key) const { return _isKey[key]; }

private:
	static InputSystem* instance;
	bool _isKeyDown[256];
	bool _isKeyUp[256];
	bool _isKey[256];
};

