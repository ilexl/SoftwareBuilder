#include <SoftwareBuilder.h>
#include "imgui/imgui.h"

class ExampleLayer : public SoftwareBuilder::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{

	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
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
	}
	~Sandbox() {

	}
};

SoftwareBuilder::Application* SoftwareBuilder::CreateApplication()
{
	return new Sandbox();
}