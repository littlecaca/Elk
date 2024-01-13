#pragma once

#include <Elk/Layer.h>
#include <Elk/Events/KeyEvent.h>
#include <Elk/Events/MouseEvent.h>
#include <Elk/Events/ApplicationEvent.h>

namespace Elk
{
	class ELK_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach();
		virtual void OnDetach();
		virtual void OnUpdate();
		virtual void OnEvent(Event &);

	private:
		bool OnMouseButtonPressedEvent(MouseButtonPressedEvent &);
		bool OnMouseButtonReleasedEvent(MouseButtonReleasedEvent &);
		bool OnMouseScrolledEvent(MouseScrolledEvent &);
		bool OnMouseMovedEvent(MouseMovedEvent &);
		bool OnKeyPressedEvent(KeyPressedEvent &);
		bool OnKeyReleasedEvent(KeyReleasedEvent &);
		bool OnWindowResizeEvent(WindowResizeEvent &);
		bool OnKeyTypedEvent(KeyTypedEvent &);

	private:
		float m_Time = 0;
	};
}