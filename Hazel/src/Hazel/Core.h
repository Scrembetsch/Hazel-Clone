#pragma once

#ifdef HAZEL_PLATFORM_WINDOWS
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else
		#define HAZEL_API __declspec(dllimport)
	#endif
#elif defined(HAZEL_PLATFORM_UNIX)
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#endif
#else
	#error Only Windows Support
#endif