#include "Time.h"
#include "Log.h"
#include <cmath>

void Time::Init()
{
	StartTime = Clock::now();
	DeltaTime = 0.0;
	SetFixedFps(50U);
	SetVSyncFps(60U);
}

double Time::GetTimeSinceStartup()
{
	return std::chrono::duration<double>(Clock::now() - StartTime).count();
}

void Time::SetFixedFps(std::uint32_t fps)
{
	FixedFps = fps;
	FixedFrameTime = 1.0 / static_cast<double>(FixedFps);
	LEBAKAS_CORE_INFO("Changed Update FPS Target to: " + std::to_string(fps));
}

void Time::SetFixedFrameTime(double frameTime)
{
	SetFixedFps(static_cast<std::uint32_t>(std::round(1.0 / frameTime)));
}

void Time::SetVSyncFps(std::uint32_t fps)
{
	fps = fps == 0 ? 99999 : fps;
	VSyncFps = fps;
	VSyncFrameTime = 1.0 / static_cast<double>(VSyncFps);
	LEBAKAS_CORE_INFO("Changed Rener FPS Target to: " + std::to_string(fps));
}

std::uint32_t Time::GetFixedFps()
{
	return FixedFps;
}

double Time::GetFixedFrameTime()
{
	return FixedFrameTime;
}

std::uint32_t Time::GetVSyncFps()
{
	return VSyncFps;
}

double Time::GetVSyncFrameTime()
{
	return VSyncFrameTime;
}

void Time::SetDeltaTime(double deltaTime)
{
	DeltaTime = deltaTime;
}

double Time::GetDeltaTime()
{
	return DeltaTime;
}