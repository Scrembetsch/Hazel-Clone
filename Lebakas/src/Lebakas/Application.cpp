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

	void Application::Update(double deltaTime)
	{
	}

	void Application::Run()
	{
		double renderPrevious = Time::GetTimeSinceStartup();
		double updatePrevious = Time::GetTimeSinceStartup();

		double lag = 0.0;

		while (mRenderer.IsWindowOpen())
		{
			double renderCurrent = Time::GetTimeSinceStartup();
			Time::SetDeltaTime(renderCurrent - renderPrevious);
			renderPrevious = renderCurrent;

			lag += Time::GetDeltaTime();

			while (lag >= Time::GetFixedFrameTime())
			{
				ProcessInput();

				double updateCurrent = Time::GetTimeSinceStartup();

				Update(updateCurrent - updatePrevious);

				updatePrevious = updateCurrent;
				lag -= Time::GetFixedFrameTime();
			}

			mRenderer.Render();
		}
	}
}