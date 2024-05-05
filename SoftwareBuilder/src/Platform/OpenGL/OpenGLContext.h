#pragma once

#include "SoftwareBuilder/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace SoftwareBuilder {

	class OpenGLContext : public GraphicsContext
	{
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* m_WindowHandle;
	};

}