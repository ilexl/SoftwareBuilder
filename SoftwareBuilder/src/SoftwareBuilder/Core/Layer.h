#pragma once

#include "SoftwareBuilder/Core/Core.h"
#include "SoftwareBuilder/Core/Timestep.h"
#include "SoftwareBuilder/Events/Event.h"

namespace SoftwareBuilder {

	class SOFTWAREBUILDER_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer() = default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}