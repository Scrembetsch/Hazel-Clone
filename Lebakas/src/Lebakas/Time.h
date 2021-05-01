#pragma once
#include "Core.h"
#include <chrono>

class LEBAKAS_API Time
{
public:
	using Clock = std::chrono::system_clock;
	/// <summary>
	/// Inits all variables
	/// </summary>
	static void Init();
	/// <summary>
	/// Get time since Init() was called (typically at start of appilcation by the engine)
	/// </summary>
	/// <returns></returns>
	static double GetTimeSinceStartup();
	
	/// <summary>
	/// Set the FPS for the fixed timesteps
	/// </summary>
	/// <param name="fps"></param>
	static void SetFixedFps(std::uint32_t fps);
	/// <summary>
	/// Rounds the result of 1 / frameTime to the closest integer value, then calls SetFixedFps to set set fixed timestep
	/// </summary>
	/// <param name="frameTime"></param>
	static void SetFixedFrameTime(double frameTime);

	/// <summary>
	/// Returns fixed fps
	/// </summary>
	/// <returns></returns>
	static std::uint32_t GetFixedFps();
	/// <summary>
	/// Returns fixed frame time
	/// </summary>
	/// <returns></returns>
	static double GetFixedFrameTime();

	/// <summary>
	/// Sets the delta time (time since last render call)
	/// </summary>
	/// <param name="deltaTime"></param>
	static void SetDeltaTime(double deltaTime);
	/// <summary>
	/// Gets the time since the last render call
	/// </summary>
	/// <returns></returns>
	static double GetDeltaTime();

private:
	inline static Clock::time_point StartTime;
	inline static std::uint32_t FixedFps;
	inline static double FixedFrameTime;
	inline static double DeltaTime;
};