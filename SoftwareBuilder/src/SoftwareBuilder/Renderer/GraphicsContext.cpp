#include "sbpch.h"

#include "SoftwareBuilder/Renderer/GraphicsContext.h"

#include "SoftwareBuilder/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLContext.h"

namespace SoftwareBuilder {

	Scope<GraphicsContext> GraphicsContext::Create(void* window)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    SB_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
		}

		SB_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

}
