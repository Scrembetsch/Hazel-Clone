#pragma once

#include <memory>

#include "Core.h"

// Disable warnings around third party includes
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

// Warning C5251 is not fixable with this logger interface (workaround would be more likely to break)

namespace Lebakas
{
	class LEBAKAS_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger()
		{
			return sCoreLogger;
		}

		inline static std::shared_ptr<spdlog::logger>& GetClientLogger()
		{
			return sClientLogger;
		}

	private:
		static std::shared_ptr<spdlog::logger> sCoreLogger;
		static std::shared_ptr<spdlog::logger> sClientLogger;
	};
}

// Core loggers
#define LEBAKAS_CORE_CRITICAL(...)::Lebakas::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define LEBAKAS_CORE_ERROR(...)	::Lebakas::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LEBAKAS_CORE_WARN(...)	::Lebakas::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LEBAKAS_CORE_INFO(...)	::Lebakas::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LEBAKAS_CORE_TRACE(...)	::Lebakas::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client loggers
#define LEBAKAS_CRITICAL(...)		::Lebakas::Log::GetClientLogger()->critical(__VA_ARGS__)
#define LEBAKAS_ERROR(...)		::Lebakas::Log::GetClientLogger()->error(__VA_ARGS__)
#define LEBAKAS_WARN(...)			::Lebakas::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LEBAKAS_INFO(...)			::Lebakas::Log::GetClientLogger()->info(__VA_ARGS__)
#define LEBAKAS_TRACE(...)		::Lebakas::Log::GetClientLogger()->trace(__VA_ARGS__)