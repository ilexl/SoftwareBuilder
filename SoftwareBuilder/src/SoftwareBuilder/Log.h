#pragma once

#include <memory.h>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace SoftwareBuilder {
	class SOFTWAREBUILDER_API Log
	{
	public:
		static void Init();
		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	
	};
}

// Core log macros
#define SB_CORE_TRACE(...)      ::SoftwareBuilder::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SB_CORE_INFO(...)       ::SoftwareBuilder::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SB_CORE_WARN(...)       ::SoftwareBuilder::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SB_CORE_ERROR(...)      ::SoftwareBuilder::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SB_CORE_CRITICAL(...)   ::SoftwareBuilder::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SB_TRACE(...)           ::SoftwareBuilder::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SB_INFO(...)            ::SoftwareBuilder::Log::GetClientLogger()->info(__VA_ARGS__)
#define SB_WARN(...)            ::SoftwareBuilder::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SB_ERROR(...)           ::SoftwareBuilder::Log::GetClientLogger()->error(__VA_ARGS__)
#define SB_CRITICAL(...)        ::SoftwareBuilder::Log::GetClientLogger()->critical(__VA_ARGS__)