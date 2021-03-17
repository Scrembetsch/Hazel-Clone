#pragma once

#ifdef LEBAKAS_PLATFORM_WINDOWS

extern Lebakas::Application* Lebakas::CreateApplication();

int main(int argc, char** argv)
{
	Lebakas::Log::Init();
	LEBAKAS_CORE_INFO("Initialized Log!");
	auto app = Lebakas::CreateApplication();
	app->Run();
	delete app;
}

#endif