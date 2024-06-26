#include "MainMenu.h"

MainMenu* MainMenu::instance = nullptr;

MainMenu::MainMenu()
{
}

MainMenu::~MainMenu()
{
}

void MainMenu::start()
{
	MainBG* bg = new MainBG;
	bg->SetLocation(Vector3(0, 0, 0));
	bg->SetDirectory("MainMap.bmp");
	Scene::AddGameObject(bg, (int)LAYER_GROUP::BG);
	Title* title = new Title;
	title->SetLocation(Vector3(288, 128, 0));
	title->SetDirectory("Title.bmp");
	Scene::AddGameObject(title, (int)LAYER_GROUP::TITLE);

	ButtonStart* btnStart = new ButtonStart;
	btnStart->SetLocation(Vector3(432, 480, 0));
	btnStart->SetDirectory("PlayButton.bmp");
	btnStart->Setname("Start");
	Scene::AddGameObject(btnStart, (int)LAYER_GROUP::BUTTON);
}

void MainMenu::end()
{
}

MainMenu* MainMenu::GetInstance()
{
	if (instance == nullptr) {
		instance = new MainMenu;
	}
	return instance;
}

void MainMenu::DestroyInstance()
{
	delete instance;
	instance = nullptr;
}
