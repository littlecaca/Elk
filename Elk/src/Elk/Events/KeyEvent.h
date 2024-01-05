#pragma once

#include "Event.h"

namespace Elk {

	// Abstract Base Class
	class ELK_API KeyEvent : public Event
	{
	public:
		int GetKeycode() const { return m_KeyCode; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event" << ": " << m_KeyCode;
			return ss.str();
		}

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput);

	protected:
		KeyEvent(int keycode) : m_KeyCode(keycode) {}

		int m_KeyCode;
	};

	class ELK_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, unsigned int repeatCount)
			: KeyEvent(keycode), m_RepeatCount(repeatCount) {}

		unsigned int GetRepeatCount() const { return m_RepeatCount; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << GetName() << "Event: " << m_KeyCode << ", " << m_RepeatCount;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed);

	private:
		unsigned int m_RepeatCount;
	};

	class ELK_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyReleased);
	};

	class ELK_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

		EVENT_CLASS_TYPE(KeyTyped);
	};
}