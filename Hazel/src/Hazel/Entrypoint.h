#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HAZEL_CORE_INFO("Initialized Log!");
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}

#endif