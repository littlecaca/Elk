#pragma once

#include "Application.h"

#ifdef HZ_PLATFORM_WINDOWS

extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char* argv[])
{
	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#else
	#error Hazel only support Windows!
#endif
