#include "elkpch.h"
#include "Application.h"
#include "GLFW/glfw3.h"


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Elk {
	Application::Application() 
	{
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));
	};

	void Application::Run() {
		ELK_CORE_ERROR("Welcom to the Elk Game Engine!");
				
		while (m_running)
		{
			glClearColor(0, 1, 0, 0);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	};

	Application::~Application() {};

	void Application::OnEvent(Event &e)
	{
		EventDispatcher dispatcher(e);

		dispatcher.Dispath<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosedEvent));

		ELK_CORE_INFO("{0}", e);
	}

	bool Application::onWindowClosedEvent(WindowCloseEvent &event)
	{
		m_running = false;
		return true;
	}
}