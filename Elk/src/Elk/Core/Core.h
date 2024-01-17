#pragma once

#ifdef ELK_PLATFORM_WINDOWS
	#ifdef ELK_DYNAMIC_LINK
		#ifdef ELK_BUILD_DLL
			#define ELK_API __declspec(dllexport)
		#else
			#define ELK_API __declspec(dllexport)
		#endif
	#else
		#define ELK_API
		#endif
#else
	#error Elk only support Windows!
#endif

#define BIT(x)	(1 << x)

#ifdef ELK_ENABLE_ASSERTS
	#define ELK_CORE_ASSERT(isSucceed, ...)	{ if (!(isSucceed)) { ELK_CORE_ERROR("Assert Failed {0}", __VA_ARGS__); __debugbreak(); } }
	#define ELK_ASSERT(isSucceed, ...)		{ if (!(isSucceed)) { ELK_CORE_ERROR("Assert Failed {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define ELK_CORE_ASSERT(isSucceed, ...)
	#define ELK_ASSERT(isSucceed, ...)
#endif

