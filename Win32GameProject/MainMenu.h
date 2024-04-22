#pragma once
#include "Scene.h"
#include "Title.h"
#include "MainBG.h"
#include "ButtonStart.h"

class MainMenu : public Scene {
public:
	MainMenu();
	~MainMenu();

	virtual void start();
	virtual void end();

	static MainMenu* GetInstance();
	static void DestroyInstance();

private:
	static MainMenu* instance;
};