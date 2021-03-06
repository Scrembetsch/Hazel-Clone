#pragma once

#include <memory>

#include "Core.h"

#include "spdlog/spdlog.h"

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
#define HAZEL_CORE_FATAL(...)	::Hazel::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define HAZEL_CORE_ERROR(...)	::Hazel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define HAZEL_CORE_WARN(...)	::Hazel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define HAZEL_CORE_INFO(...)	::Hazel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define HAZEL_CORE_TRACE(...)	::Hazel::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client loggers
#define HAZEL_FATAL(...)		::Hazel::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define HAZEL_ERROR(...)		::Hazel::Log::GetClientLogger()->error(__VA_ARGS__)
#define HAZEL_WARN(...)			::Hazel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define HAZEL_INFO(...)			::Hazel::Log::GetClientLogger()->info(__VA_ARGS__)
#define HAZEL_TRACE(...)		::Hazel::Log::GetClientLogger()->trace(__VA_ARGS__)