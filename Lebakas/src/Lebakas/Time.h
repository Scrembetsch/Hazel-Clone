#pragma once
#include "Core.h"
#include <chrono>

class LEBAKAS_API Time
{
public:
	using Clock = std::chrono::system_clock;
	static void Init();
	static double GetTimeSinceStartup();
	
	static void SetFixedFps(std::uint32_t fps);
	static void SetFixedFrameTime(double frameTime);

	static std::uint32_t GetFixedFps();
	static double GetFixedFrameTime();

	static void SetDeltaTime(double deltaTime);
	static double GetDeltaTime();

private:
	inline static Clock::time_point StartTime;
	inline static std::uint32_t FixedFps;
	inline static double FixedFrameTime;
	inline static double DeltaTime;
};