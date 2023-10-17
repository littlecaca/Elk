workspace "Elk"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Elk"
    location "Elk"
    kind "SharedLib"
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
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"

        defines
        {
            "ELK_PLATFORM_WINDOWS",
            "ELK_BUILD_DLL"
        }

        postbuildcommands
        {

            ("{COPY} %{cfg.buildtarget.relpath}" .. " ../bin/" .. outputdir .. "/Sandbox")
        }
        
        

    filter "configurations:Debug"
        defines "ELK_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "ELK_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "ELK_DIST"
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
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Elk/vendor/spdlog/include",
        "Elk/src"
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
    
    filter "configurations:Release"
        defines "ELK_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "ELK_DIST"
        optimize "On"