#pragma once

#include "Elk/Core/Core.h"
#include "Window.h"
#include <Elk/Events/ApplicationEvent.h>

namespace Elk {

	class ELK_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		std::unique_ptr<Window> m_Window;

	private:
		bool onWindowClosedEvent(WindowCloseEvent &);
		bool m_running = true;
		void OnEvent(Event &);
	};
	// To be define in CLIENT
	Application* CreateApplication();
}

