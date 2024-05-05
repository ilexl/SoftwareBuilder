workspace "SoftwareBuilder"
	architecture "x64"
	startproject "Sandbox"

	disablewarnings { "26498", "6285", "26800" }

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "SoftwareBuilder/vendor/GLFW/include"
IncludeDir["Glad"] = "SoftwareBuilder/vendor/Glad/include"
IncludeDir["ImGui"] = "SoftwareBuilder/vendor/imgui"
IncludeDir["glm"] = "SoftwareBuilder/vendor/glm"

group "Dependencies"
	include "SoftwareBuilder/vendor/GLFW"
	include "SoftwareBuilder/vendor/Glad"
	include "SoftwareBuilder/vendor/imgui"
group ""

project "SoftwareBuilder"
	location "SoftwareBuilder"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "sbpch.h"
	pchsource "SoftwareBuilder/src/sbpch.cpp"


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS",
			"SB_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SB_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"SoftwareBuilder/vendor/spdlog/include",
		"SoftwareBuilder/src",
		"SoftwareBuilder/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"SoftwareBuilder"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "SB_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "SB_DIST"
		runtime "Release"
		optimize "on"