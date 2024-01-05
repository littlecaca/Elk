#pragma once



#include "elkpch.h"
#include "Elk/Core/Core.h"

namespace Elk {
	/*
	 * For now, the events are blocking, which means it will be not buffered
	 * and will be executed right away once the event happens.
	 */

	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus,
		WindowMoved, AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped, MouseButtonPressed,
		MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// We may want to filter some events according to event types
	enum EventCategory
	{
		None						= 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

	// Interface
	class ELK_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char *GetName() const = 0;
		virtual std::string ToString() const { return GetName() + std::string("Event"); }
		virtual int GetCategoryFlags() const = 0;

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		virtual ~Event() = default;
		Event() : m_Handled(false) {}
	private:
		bool m_Handled;
	};

	// Event Dispather
	class EventDispather
	{
		template <typename T>
		using EventFn = std::function<bool(T &)>;
	public:
		EventDispather(Event &event) : m_Event(event) {}

		template <typename T>
		bool Dispath(EventFn<T> func)
		{
			// Make sure the m_Event and the func's parameter has the same type
			if (m_Event.GetEventType() == T::GetStaticType())
			{
				m_Event.m_Handled = func(static_cast<T &>(m_Event));
				return true;
			}
			return false;
		}

	private:
		Event &m_Event;
	};


	// For convenience to override functions in derived class
	// Because the real type of Event &(*) is probably different,
	// we need the GetStaticType (not virtual)
#define EVENT_CLASS_TYPE(type)\
	static EventType GetStaticType() { return EventType::##type; }\
	virtual EventType GetEventType() const override { return GetStaticType(); }\
	virtual const char *GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category)\
	virtual int GetCategoryFlags() const override { return category; }
}
