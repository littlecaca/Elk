#include "elkpch.h"
#include "WindowsWindow.h"

#include <Elk/Events/KeyEvent.h>
#include <Elk/Events/MouseEvent.h>
#include <Elk/Events/ApplicationEvent.h>
#include <Elk/Core/Core.h>
#include <glad/glad.h>

namespace Elk
{
	static bool s_GLFWInitialized = false;

	static void GLFWErrorCallBack(int error, const char *message)
	{
		ELK_CORE_ERROR("GLFW Error ({0}): {1}", error, message);
	}

	Window *Window::Create(const WindowProps &props)
	{
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps &props)
	{
		Init(props);
	}

	WindowsWindow::~WindowsWindow()
	{
		WindowsWindow::Shutdown();
	}

	void WindowsWindow::Init(const WindowProps &props)
	{
		m_Data.Height = props.Height;
		m_Data.Width = props.Width;
		m_Data.Title = props.Title;

		ELK_CORE_INFO("Createing Window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!s_GLFWInitialized)
		{
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			ELK_CORE_ASSERT(success, "Countn't initialize GLFW!");

			s_GLFWInitialized = true;

			glfwSetErrorCallback(&GLFWErrorCallBack);
		}

		m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(m_Window);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		ELK_CORE_ASSERT(status, "Failed to initialize Glad");
		glfwSetWindowUserPointer(m_Window, &m_Data);
		SetVSync(true);
		
		// Set GLFW callbacks
		glfwSetWindowSizeCallback(m_Window, [](GLFWwindow *window, int width, int height) 
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);
			data->Width = width;
			data->Height = height;

			WindowResizeEvent event(width, height);
			data->EventCallback(event);
		});

		glfwSetWindowCloseCallback(m_Window, [](GLFWwindow *window)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			WindowCloseEvent event;
			data->EventCallback(event);
		});

		glfwSetKeyCallback(m_Window, [](GLFWwindow *window, int key, int scancode, int action, int mods)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, 0);
					data->EventCallback(event);
					break;
				}

				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data->EventCallback(event);
					break;
				}

				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, 1);
					data->EventCallback(event);
					break;
				}
			}
		});

		glfwSetMouseButtonCallback(m_Window, [](GLFWwindow *window, int button, int action, int mods)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			switch (action)
			{
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data->EventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data->EventCallback(event);
					break;
				}
		
			}
		});

		glfwSetScrollCallback(m_Window, [](GLFWwindow *window, double x_offset, double y_offset)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			MouseScrolledEvent event((float)x_offset, (float)y_offset);
			data->EventCallback(event);
		});

		glfwSetCursorPosCallback(m_Window, [](GLFWwindow *window, double x_pos, double y_pos)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			MouseMovedEvent event((float)x_pos, (float)y_pos);
			data->EventCallback(event);
		});

		glfwSetCharCallback(m_Window, [](GLFWwindow *window, unsigned int keycode)
		{
			WindowData *data = (WindowData *)glfwGetWindowUserPointer(window);

			KeyTypedEvent event((int)keycode);
			data->EventCallback(event);
		});
	}

	void WindowsWindow::Shutdown()
	{
		glfwDestroyWindow(m_Window);
	}

	void WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(m_Window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		m_Data.VSync = enabled;
	}

	bool WindowsWindow::IsVSync() const
	{
		return m_Data.VSync;
	}

}