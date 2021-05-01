#include "Application.h"
#include "Time.h"
#include "SFML/Graphics.hpp"
#include "Log.h"

namespace Lebakas
{
	Application::Application()
	{
		Time::Init();
		Device::Input::Init();
	}

	Application::~Application()
	{
	}

	void Application::ProcessInput()
	{
		Device::Input::Update();
		Event event;
		while ((event = mRenderer.PollEvent()).EventType != Event::NONE)
		{
			switch (event.EventType)
			{
				case Event::Type::KEY_PRESSED:
					Device::Input::KeyPressed(event.Key);
					break;

				case Event::Type::KEY_RELEASED:
					Device::Input::KeyReleased(event.Key);
					break;

				default:
					break;
			}
		}
	}

	void Application::FixedUpdate(double deltaTime)
	{
	}

	void Application::Run()
	{
		double renderPrevious = Time::GetTimeSinceStartup();
		double updatePrevious = Time::GetTimeSinceStartup();

		double updateLag = 0.0;
		double renderLag = 0.0;

		while (mRenderer.IsWindowOpen())
		{
			double renderCurrent = Time::GetTimeSinceStartup();
			Time::SetDeltaTime(renderCurrent - renderPrevious);
			renderPrevious = renderCurrent;

			updateLag += Time::GetDeltaTime();
			renderLag += Time::GetDeltaTime();

			while (updateLag >= Time::GetFixedFrameTime())
			{
				ProcessInput();

				double updateCurrent = Time::GetTimeSinceStartup();

				FixedUpdate(updateCurrent - updatePrevious);

				updatePrevious = updateCurrent;
				updateLag -= Time::GetFixedFrameTime();
			}

			if (renderLag >= Time::GetVSyncFrameTime())
			{
				mRenderer.Render();
				renderLag -= Time::GetVSyncFrameTime();
			}
		}
	}
}