#pragma once

#include "Window.h"
#include "SoftwareBuilder/Core.h"
#include "SoftwareBuilder/LayerStack.h"
#include "SoftwareBuilder/Events/Event.h"
#include "SoftwareBuilder/Events/ApplicationEvent.h"

#include "SoftwareBuilder/ImGui/ImGuiLayer.h"

#include "SoftwareBuilder/Renderer/Shader.h"

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
		inline Window& GetWindow() { return *m_Window; }
		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
		unsigned int m_VertexArray, m_VertexBuffer, m_IndexBuffer;
		std::unique_ptr<Shader> m_Shader;
	private:
		static Application* s_Instance;
	};

	// To be defined in a client
	Application* CreateApplication();
}


