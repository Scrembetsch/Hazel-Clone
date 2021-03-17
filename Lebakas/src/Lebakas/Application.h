#pragma once

#include "Core.h"

namespace Lebakas
{
	class LEBAKAS_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// Define in client
	Application* CreateApplication();
}
