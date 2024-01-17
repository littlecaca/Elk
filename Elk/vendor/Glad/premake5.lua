project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/Glad.c",
		"include/Glad/Glad.h",
		"include/KHR/khrplatform.h",
	}

	includedirs
	{
		"include"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "speed"

