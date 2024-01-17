workspace "Elk"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "Elk/vendor/GLFW/include"
IncludeDir["Glad"] = "Elk/vendor/Glad/include"
IncludeDir["ImGui"] = "Elk/vendor/imgui"
IncludeDir["glm"] = "Elk/vendor/glm"

include "Elk/vendor/GLFW"
include "Elk/vendor/Glad"
include "Elk/vendor/imgui"

project "Elk"
	location "Elk"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"


	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "elkpch.h"
	pchsource "Elk/src/elkpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
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
			"ELK_PLATFORM_WINDOWS",
			"GLFW_INCLUDE_NONE",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
			"_CRT_SECURE_NO_WARNINGS"
		}


	filter "configurations:Debug"
		defines 
		{
			"ELK_DEBUG",
			"ELK_ENABLE_ASSERTS"
		}
		symbols "on"
		runtime "Debug"
	
	filter "configurations:Release"
		defines "ELK_RELEASE"
		optimize "on"
		runtime "Release"
	
	filter "configurations:Dist"
		defines "ELK_DIST"
		optimize "on"
		runtime "Release"


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
		"Elk/vendor/spdlog/include",
		"Elk/src",
		"Elk/vendor",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Elk",
	}

	filter "system:windows"
		staticruntime "On"
		systemversion "latest"
		

		defines
		{
			"ELK_PLATFORM_WINDOWS",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
		}

	filter "configurations:Debug"
		defines "ELK_DEBUG"
		symbols "on"
		runtime "Debug"
	
	filter "configurations:Release"
		defines "ELK_RELEASE"
		optimize "on"
		runtime "Release"
	
	filter "configurations:Dist"
		defines "ELK_DIST"
		optimize "on"
		runtime "Release"