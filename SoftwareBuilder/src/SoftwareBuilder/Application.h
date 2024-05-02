#pragma once

#include "SoftwareBuilder/Core.h"

namespace SoftwareBuilder {
	class SOFTWAREBUILDER_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();


	};

	// To be defined in a client
	Application* CreateApplication();
}


