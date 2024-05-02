#include <SoftwareBuilder.h>

class ExampleLayer : public SoftwareBuilder::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		SB_INFO("ExampleLayer::Update");
	}

	void OnEvent(SoftwareBuilder::Event& event) override
	{
		SB_TRACE("{0}", event);
	}

};

class Sandbox : public SoftwareBuilder::Application
{
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}
	~Sandbox() {

	}
};

SoftwareBuilder::Application* SoftwareBuilder::CreateApplication()
{
	return new Sandbox();
}