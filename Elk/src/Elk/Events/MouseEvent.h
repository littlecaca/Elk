#pragma once

#include "Event.h"

namespace Elk {
	class ELK_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float mouseX, float mouseY)
			: m_MouseX(mouseX), m_MouseY(mouseY) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << m_MouseX << ", " << m_MouseY << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseMoved);

	private:
		float m_MouseX, m_MouseY;
	};

	class ELK_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float offsetX, float offsetY)
			: m_OffsetX(offsetX), m_OffsetY(offsetY) {}

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << m_OffsetX << ", " << m_OffsetY << ")";
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouse);
		EVENT_CLASS_TYPE(MouseScrolled);
		
	private:
		float m_OffsetX, m_OffsetY;
	};

	// Abstract Base Class
	class ELK_API MouseButtonEvent : public Event
	{
	public:
		MouseCode GetMouseButton() const { return m_Button; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_Button;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryMouseButton);

	protected:
		MouseButtonEvent(MouseCode button) : m_Button(button) {}
		MouseCode m_Button;
	};

	class ELK_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(MouseCode button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonPressed);
	};

	class ELK_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(MouseCode button) : MouseButtonEvent(button) {}

		EVENT_CLASS_TYPE(MouseButtonReleased);
	};
	
}