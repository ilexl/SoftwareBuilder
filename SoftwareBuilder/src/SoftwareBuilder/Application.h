#pragma once

#include "SoftwareBuilder/Core.h"
#include "Window.h"

namespace SoftwareBuilder {
	class SOFTWAREBUILDER_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
	private:
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be defined in a client
	Application* CreateApplication();
}


