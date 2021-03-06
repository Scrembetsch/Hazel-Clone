#pragma once

#include <memory>

#include "Core.h"

// Disable warnings around third party includes
#pragma warning(push, 0)
#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#pragma warning(pop)

// Warning C5251 is not fixable with this logger interface (workaround would be more likely to break)

namespace Hazel
{
	class HAZEL_API Log
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
#define HAZEL_CORE_CRITICAL(...)::Hazel::Log::GetCoreLogger()->critical(__VA_ARGS__)
#define HAZEL_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HAZEL_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HAZEL_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HAZEL_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client loggers
#define HAZEL_CRITICAL(...)		::Hazel::Log::GetClientLogger()->critical(__VA_ARGS__)
#define HAZEL_ERROR(...)		::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HAZEL_WARN(...)			::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HAZEL_INFO(...)			::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HAZEL_TRACE(...)		::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)