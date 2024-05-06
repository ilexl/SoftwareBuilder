#pragma once
#include "SoftwareBuilder.h"

class Sandbox2D : public SoftwareBuilder::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(SoftwareBuilder::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(SoftwareBuilder::Event& e) override;
private:
	SoftwareBuilder::OrthographicCameraController m_CameraController;

	// Temp
	SoftwareBuilder::Ref<SoftwareBuilder::VertexArray> m_SquareVA;
	SoftwareBuilder::Ref<SoftwareBuilder::Shader> m_FlatColorShader;

	SoftwareBuilder::Ref<SoftwareBuilder::Texture2D> m_CheckerboardTexture;

	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};

