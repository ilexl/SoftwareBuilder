#pragma once

#include "SoftwareBuilder/Core/Core.h"

#ifdef SB_PLATFORM_WINDOWS

extern SoftwareBuilder::Application* SoftwareBuilder::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Software Builder\n");

	SoftwareBuilder::Log::Init();
	SB_CORE_INFO("Logger Initialized!");

	SB_PROFILE_BEGIN_SESSION("Startup", "Software BuilderProfile-Startup.json");
	auto app = SoftwareBuilder::CreateApplication();
	SB_PROFILE_END_SESSION();

	SB_PROFILE_BEGIN_SESSION("Runtime", "Software BuilderProfile-Runtime.json");
	app->Run();
	SB_PROFILE_END_SESSION();

	SB_PROFILE_BEGIN_SESSION("Startup", "Software BuilderProfile-Shutdown.json");
	delete app;
	SB_PROFILE_END_SESSION();
}

#endif