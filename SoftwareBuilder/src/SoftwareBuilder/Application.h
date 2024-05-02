#pragma once

#include "SoftwareBuilder/Core.h"
#include "Window.h"
#include "SoftwareBuilder/Events/ApplicationEvent.h"

namespace SoftwareBuilder {
	class SOFTWAREBUILDER_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;

	};

	// To be defined in a client
	Application* CreateApplication();
}


