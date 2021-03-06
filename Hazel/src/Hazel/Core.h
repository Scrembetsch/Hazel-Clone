#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#elif defined(HAZEL_PLATFORM_UNIX)
	#define HAZEL_API
#else
	#error Only Windows Support
#endif