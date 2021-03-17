#include "Log.h"

namespace Lebakas
{
	std::shared_ptr<spdlog::logger> Log::sCoreLogger;
	std::shared_ptr<spdlog::logger> Log::sClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		sCoreLogger = spdlog::stdout_color_mt("Hazel");
		sCoreLogger->set_level(spdlog::level::level_enum::info);
		sClientLogger = spdlog::stdout_color_mt("Client");
	}
}
