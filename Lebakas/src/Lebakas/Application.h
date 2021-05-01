#pragma once

#include "Core.h"
#include "WindowManager.h"

namespace Lebakas
{
	class LEBAKAS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
		void ProcessInput();

		virtual void Update(double deltaTime);

	protected:
		WindowManager mRenderer;
	};

	// Define in client
	Application* CreateApplication();
}
