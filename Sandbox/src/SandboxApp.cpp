#include <SoftwareBuilder.h>

class ExampleLayer : public SoftwareBuilder::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{

	}

	void OnEvent(SoftwareBuilder::Event& event) override
	{

	}

};

class Sandbox : public SoftwareBuilder::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
		PushOverlay(new SoftwareBuilder::ImGuiLayer());
	}
	~Sandbox() {

	}
};

SoftwareBuilder::Application* SoftwareBuilder::CreateApplication()
{
	return new Sandbox();
}