#pragma once

#include "Elk/Core/Core.h"
#include "Window.h"
#include <Elk/Events/ApplicationEvent.h>
#include "LayerStack.h"
#include "Input.h"

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

		inline static Application &Get() { return *s_Instance; }
		inline Window &GetWindow() const { return *m_Window; }

	private:
		bool onWindowClosed(WindowCloseEvent &);
		bool m_running = true;
		void OnEvent(Event &);
		LayerStack m_LayerStack;
		static Application *s_Instance;
		
	};
	// To be define in CLIENT
	Application* CreateApplication();
}

