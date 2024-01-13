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

include "Elk/vendor/GLFW"
include "Elk/vendor/Glad"
include "Elk/vendor/imgui"

project "Elk"
    location "Elk"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "elkpch.h"
    pchsource "Elk/src/elkpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
    }

    links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "ELK_PLATFORM_WINDOWS",
            "ELK_BUILD_DLL",
            "GLFW_INCLUDE_NONE",
            "IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
        }

        postbuildcommands
        {

            ("{COPY} %{cfg.buildtarget.relpath}" .. " ../bin/" .. outputdir .. "/Sandbox")
        }
        
        

    filter "configurations:Debug"
        defines 
        {
            "ELK_DEBUG",
            "ELK_ENABLE_ASSERTS"
        }
        symbols "On"
        staticruntime "off"
        runtime "Debug"
    
    filter "configurations:Release"
        defines "ELK_RELEASE"
        optimize "On"
        staticruntime "off"
        runtime "Release"
        
    
    filter "configurations:Dist"
        defines "ELK_DIST"
        optimize "On"
        staticruntime "off"
        runtime "Release"


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

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
		"%{IncludeDir.Glad}"

    }

    links
    {
        "Elk"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"
        

        defines
        {
            "ELK_PLATFORM_WINDOWS",
        }
        

    filter "configurations:Debug"
        defines "ELK_DEBUG"
        symbols "On"
        staticruntime "off"
        runtime "Debug"
    
    filter "configurations:Release"
        defines "ELK_RELEASE"
        optimize "On"
        staticruntime "off"
        runtime "Release"
    
    filter "configurations:Dist"
        defines "ELK_DIST"
        optimize "On"
        staticruntime "off"
        runtime "Release"