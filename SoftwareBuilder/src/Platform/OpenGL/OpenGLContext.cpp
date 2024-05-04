#include "sbpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>
#include <GL/GL.h>

namespace SoftwareBuilder {

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		SB_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		SB_CORE_ASSERT(status, "Failed to initialize Glad!");

		SB_CORE_INFO("*");
		SB_CORE_INFO("OpenGL Info:");
		SB_CORE_INFO("Vendor: {0}", (const char*)glGetString(GL_VENDOR));
		SB_CORE_INFO("Renderer: {0}", (const char*)glGetString(GL_RENDERER));
		SB_CORE_INFO("Version: {0}", (const char*)glGetString(GL_VERSION));
		SB_CORE_INFO("*");

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}
}

