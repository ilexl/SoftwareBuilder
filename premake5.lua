workspace "SoftwareBuilder"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "SoftwareBuilder"
	location "SoftwareBuilder"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS",
			"SB_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "SB_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SB_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"SoftwareBuilder/vendor/spdlog/include",
		"SoftwareBuilder/src"
	}

	links
	{
		"SoftwareBuilder"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"SB_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "SB_DEBUG"
		symbols "On"

	filter "configurations:Debug"
		defines "SB_RELEASE"
		optimize "On"

	filter "configurations:Debug"
		defines "SB_DIST"
		optimize "On"