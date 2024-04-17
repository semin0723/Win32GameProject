#include "GameManager.h"
#include "Win32GameProject.h"
#include "SceneManager.h"
#include "InputSystem.h"
#include "TimeSystem.h"
#include "RenderSystem.h"

namespace game
{

	GameManager* GameManager::instance = nullptr;
	GameManager::GameManager()
	{
	}
	GameManager::~GameManager()
	{
	}
	void GameManager::Initialize()
	{		
		SceneManager::GetInstance()->InitScene();
	}

	void GameManager::Update()
	{
		TimeManager::GetInstance()->UpdateTime();
		InputSystem::GetInstance()->updateMouse();
		SceneManager::GetInstance()->update();
		InputSystem::GetInstance()->ResetInput();
	}

	void GameManager::FixeUpdate()
	{
		
	}

	void GameManager::Render()
	{
		RenderSystem::GetInstance()->StartDraw();
		SceneManager::GetInstance()->render(RenderSystem::GetInstance()->_backDC, global::GetWinApp().GetInstance());
		RenderSystem::GetInstance()->EndDraw();
	}
	void GameManager::Finalize()
	{
		TimeManager::DeleteInstance();
		RenderSystem::DestroyInstance();
	}
	void GameManager::Run()
	{
		MSG msg;

		while (true)
		{
			if (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
			{
				if (msg.message == WM_QUIT) break;

				if (msg.message == WM_KEYDOWN)
				{
					InputSystem::GetInstance()->KeyDown(msg.wParam);
				}
				else if (msg.message == WM_KEYUP)
				{
					InputSystem::GetInstance()->KeyUp(msg.wParam);
				}
				else
				{
					DispatchMessage(&msg);
				}
			}
			else
			{
				FixeUpdate();

				Update();

				Render();
			}
		}
	}

	GameManager* GameManager::GetInstance()
	{
		if (instance == nullptr)
		{
			instance = new GameManager();
		}
		return instance;
	}
	void GameManager::DestroyInstance()
	{
		if (instance != nullptr)
		{
			delete instance;
			instance = nullptr;
		}
	}
}