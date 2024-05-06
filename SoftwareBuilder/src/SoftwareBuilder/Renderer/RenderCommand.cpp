#include "sbpch.h"
#include "SoftwareBuilder/Renderer/RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace SoftwareBuilder {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();
}