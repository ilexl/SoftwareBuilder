#pragma once

#include "Window.h"
#include "SoftwareBuilder/Core.h"
#include "SoftwareBuilder/LayerStack.h"
#include "SoftwareBuilder/Events/Event.h"
#include "SoftwareBuilder/Events/ApplicationEvent.h"

namespace SoftwareBuilder {
	class SOFTWAREBUILDER_API Application
	{

	public:
		Application();
		virtual ~Application();
		void Run();
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		bool m_Running = true;
		LayerStack m_LayerStack;
	};

	// To be defined in a client
	Application* CreateApplication();
}


