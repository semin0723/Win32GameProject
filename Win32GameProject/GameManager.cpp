#include "GameManager.h"
#include "Win32GameProject.h"
#include "SceneManager.h"
//#include "InputSystem.h"
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
		/*input::InitInput();
		time::InitTime();
		render::InitRender();*/
		SceneManager::GetInstance()->InitScene();
	}

	void GameManager::Update()
	{
		/*++m_UpdateCount;

		input::UpdateMouse();

		time::UpdateTime();

		UpdatePlayer();
		UpdateBlueCircle();

		input::ResetInput();*/
		TimeManager::GetInstance()->UpdateTime();
		SceneManager::GetInstance()->update();
	}

	void GameManager::FixeUpdate()
	{
		//static ULONGLONG elapsedTime;

		//elapsedTime += time::GetDeltaTime();

		//while (elapsedTime >= 20) //0.02ÃÊ
		//{
		//	++m_FixedUpdateCount;

		//	elapsedTime -= 20;
		//}
	}

	void GameManager::Render()
	{
		/*render::BeginDraw();

		DrawFPS();
		DrawSomething();
		DrawPlayer();

		render::EndDraw();*/
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
					//input::KeyDown(msg.wParam);
				}
				else if (msg.message == WM_KEYUP)
				{
					//input::KeyUp(msg.wParam);
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

	void GameManager::DrawFPS()
	{
		/*static ULONGLONG elapsedTime;
		static int UpdateCount;
		static int FixedUpdateCount;

		elapsedTime += time::GetDeltaTime();

		if (elapsedTime >= 1000)
		{
			elapsedTime = 0;
			;
			UpdateCount = m_UpdateCount;
			FixedUpdateCount = m_FixedUpdateCount;

			m_UpdateCount = 0;
			m_FixedUpdateCount = 0;
		}

		std::string str = "FPS: " + std::to_string(time::GetFrameRate());
		str += "           Update " + std::to_string(UpdateCount);
		str += "           FixedUpdate " + std::to_string(FixedUpdateCount);

		render::DrawText(10, 10, str.c_str(), RGB(255, 0, 0));*/

	}

	void GameManager::DrawPlayer()
	{
		//render::DrawCircle(player.x, player.y, player.size, player.color);
	}

	void GameManager::DrawSomething()
	{

		/*for (int i = 0; i < blueCircleCount; i++)
		{
			render::DrawCircle(blueCircles[i].x, blueCircles[i].y, blueCircles[i].size, blueCircles[i].color);
		}

		render::DrawLine(player.x - 50, player.y + 50, player.x + 50, player.y + 50, RGB(255, 0, 0));
		render::DrawRect(player.x - 25, player.y - 25, 50, 50, RGB(255, 0, 255));*/

	}
}