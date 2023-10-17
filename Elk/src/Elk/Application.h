#pragma once

#include "Core.h"

namespace Elk {

	class ELK_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	// To be define in CLIENT
	Application* CreateApplication();
}

