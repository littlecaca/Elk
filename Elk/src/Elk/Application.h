#pragma once

#include "Elk/Core/Core.h"
#include "Window.h"
#include <Elk/Events/ApplicationEvent.h>
#include "LayerStack.h"

namespace Elk {

	class ELK_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();

		std::unique_ptr<Window> m_Window;

		void PushLayer(Layer *layer);
		void PushOverlay(Layer *layer);

	private:
		bool onWindowClosed(WindowCloseEvent &);
		bool m_running = true;
		void OnEvent(Event &);
		LayerStack m_LayerStack;
		
	};
	// To be define in CLIENT
	Application* CreateApplication();
}

