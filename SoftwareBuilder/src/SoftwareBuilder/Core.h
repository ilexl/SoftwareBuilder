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

#ifdef HZ_ENABLE_ASSERTS
	#define SB_ASSERT(x, ...) { if(!(x)) { HZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define SB_CORE_ASSERT(x, ...) { if(!(x)) { HZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define SB_ASSERT(x, ...)
	#define SB_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define SB_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)