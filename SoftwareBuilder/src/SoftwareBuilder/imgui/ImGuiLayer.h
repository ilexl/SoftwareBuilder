#pragma once

#include "SoftwareBuilder/Core/Layer.h"

#include "SoftwareBuilder/Events/ApplicationEvent.h"
#include "SoftwareBuilder/Events/KeyEvent.h"
#include "SoftwareBuilder/Events/MouseEvent.h"

namespace SoftwareBuilder {
	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer() = default;

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}

