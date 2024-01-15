#include "elkpch.h"
#include "Application.h"
#include "Glad/glad.h"

#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Elk {
	// Single instance mode
	Application *Application::s_Instance = nullptr;

	Application::Application() 
	{
		ELK_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback(BIND_EVENT_FN(OnEvent));

		unsigned int id;
		glGenVertexArrays(1, &id);
	};

	void Application::Run() {
		ELK_CORE_INFO("Welcom to the Elk Game Engine!");
				
		while (m_running)
		{
			glClearColor(0, 1, 0, 0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (auto layer : m_LayerStack)
			{
				layer->OnUpdate();
			}


			m_Window->OnUpdate();
		}
	};

	Application::~Application() {};

	void Application::OnEvent(Event &e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispath<WindowCloseEvent>(BIND_EVENT_FN(onWindowClosed));

		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
		{
			(*--it)->OnEvent(e);
			if (e.m_Handled)
				break;
		}
	}

	bool Application::onWindowClosed(WindowCloseEvent &event)
	{
		m_running = false;
		return true;
	}

	void Application::PushLayer(Layer *layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer *overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}


}