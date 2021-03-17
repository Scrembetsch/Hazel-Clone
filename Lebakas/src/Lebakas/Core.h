#pragma once

#ifdef LEBAKAS_PLATFORM_WINDOWS
	#ifdef LEBAKAS_BUILD_DLL
		#define LEBAKAS_API __declspec(dllexport)
	#else
		#define LEBAKAS_API __declspec(dllimport)
	#endif
#elif defined(LEBAKAS_PLATFORM_UNIX)
	#define LEBAKAS_API
#else
	#error Only Windows Support
#endif