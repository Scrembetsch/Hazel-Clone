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
		while ((event = mRenderer.GetLatestEvent()).EventType != Event::NONE)
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

	void Application::Update(float deltaTime)
	{
	}

	void Application::Run()
	{
		double previous = Time::GetTimeSinceStartup();
		double lag = 0.0;
		while (mRenderer.IsWindowOpen())
		{
			double current = Time::GetTimeSinceStartup();
			Time::SetDeltaTime(current - previous);
			previous = current;
			lag += Time::GetDeltaTime();

			while (lag >= Time::GetFixedFrameTime())
			{
				ProcessInput();
				Update(Time::GetFixedFrameTime());
				lag -= Time::GetFixedFrameTime();
			}

			mRenderer.Render();
		}
	}
}