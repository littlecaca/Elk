<<<<<<< HEAD
#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
=======
#include "elkpch.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "Log.h"
>>>>>>> 9614ee7 (Add the precompiled header)

namespace Elk {
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("Elk");
		s_CoreLogger->set_level(spdlog::level::level_enum::trace);
		s_ClientLogger = spdlog::stdout_color_mt("App");
		s_ClientLogger->set_level(spdlog::level::level_enum::trace);
	}
}