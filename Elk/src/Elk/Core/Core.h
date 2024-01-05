#pragma once

#ifdef ELK_PLATFORM_WINDOWS
	#ifdef ELK_BUILD_DLL
		#define ELK_API __declspec(dllexport)
	#else
		#define ELK_API __declspec(dllimport)
	#endif
#else
	#error Elk only support Windows!
#endif

#define BIT(x)	(1 << x)