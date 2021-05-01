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

		/// <summary>
		/// Update Function -> override to receive update call every fixed time step
		/// </summary>
		/// <param name="deltaTime">Time since last update</param>
		virtual void FixedUpdate(double deltaTime);

	protected:
		/// <summary>
		/// Window Manager that uses SFML to render
		/// </summary>
		WindowManager mRenderer;

	private:
		/// <summary>
		/// Collects all events from window manager and edits entries in Device::Input
		/// </summary>
		void ProcessInput();
	};

	// Define in client
	Application* CreateApplication();
}
