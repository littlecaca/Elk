#pragma once

#include "Application.h"
#include "Log.h"

#ifdef ELK_PLATFORM_WINDOWS

extern Elk::Application* Elk::CreateApplication();

int main(int argc, char* argv[])
{
	Elk::Log::Init();
	auto &coreLogger = Elk::Log::GetCoreLogger();
	ELK_CORE_WARN("Core Info ~~~~~~~~");
	ELK_TRACE("Client Info blablabla {0:8}", 8);
	ELK_ERROR("There is an error");
	auto app = Elk::CreateApplication();
	app->Run();
	delete app;
	return 0;
}

#else
	#error Elk only support Windows!
#endif
