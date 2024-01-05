#pragma once


#include "Elk/Core/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Elk {

	class ELK_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger;  }
	private:
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Core log macros
#define ELK_CORE_TRACE(...)		::Elk::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define ELK_CORE_INFO(...)		::Elk::Log::GetCoreLogger()->info(__VA_ARGS__)
#define ELK_CORE_WARN(...)		::Elk::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define ELK_CORE_ERROR(...)		::Elk::Log::GetCoreLogger()->error(__VA_ARGS__)
#define ELK_CORE_FATAL(...)		::Elk::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define ELK_TRACE(...)			::Elk::Log::GetClientLogger()->trace(__VA_ARGS__)
#define ELK_INFO(...)			::Elk::Log::GetClientLogger()->info(__VA_ARGS__)
#define ELK_WARN(...)			::Elk::Log::GetClientLogger()->warn(__VA_ARGS__)
#define ELK_ERROR(...)			::Elk::Log::GetClientLogger()->error(__VA_ARGS__)
#define ELK_FATAL(...)			::Elk::Log::GetClientLogger()->fatal(__VA_ARGS__)

