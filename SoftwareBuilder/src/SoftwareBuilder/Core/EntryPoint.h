#pragma once

#include "SoftwareBuilder/Core/Core.h"

#ifdef SB_PLATFORM_WINDOWS

extern SoftwareBuilder::Application* SoftwareBuilder::CreateApplication();

int main(int argc, char** argv) 
{
	printf("Software Builder\n");

	SoftwareBuilder::Log::Init();
	SB_CORE_INFO("Logger Initialized!");

	auto app = SoftwareBuilder::CreateApplication();
	app->Run();
	delete app;
}

#endif