#pragma once

#include "SoftwareBuilder/Core/Window.h"
#include "SoftwareBuilder/Core/Core.h"
#include "SoftwareBuilder/Core/LayerStack.h"
#include "SoftwareBuilder/Events/Event.h"
#include "SoftwareBuilder/Events/ApplicationEvent.h"
#include "SoftwareBuilder/Core/Timestep.h"
#include "SoftwareBuilder/ImGui/ImGuiLayer.h"

namespace SoftwareBuilder {
	class Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
	};

	// To be defined in a client
	Application* CreateApplication();
}


