#pragma once

#ifdef SB_PLATFORM_WINDOWS
	#ifdef SB_BUILD_DLL
		#define SOFTWAREBUILDER_API __declspec(dllexport)
	#else
		#define SOFTWAREBUILDER_API __declspec(dllimport)
	#endif // SB_BUILD_DLL
#else
	#error Software Builder only supports Windows!
#endif