#pragma once

<<<<<<< HEAD
#include <string>
#include <functional>
#include "../Core.h"
=======
#include "Elk/Core/Core.h"
#include "Elk/Core/MouseCodes.h"
#include "elkpch.h"
>>>>>>> 9614ee7 (Add the precompiled header)

namespace Elk {
	/*
	 * For now, the events are blocking, which means it will be not buffered
	 * and will be executed right away once the event happens.
	 */

	enum class EventType
	{
		None = 0,
		Windowclose, WindowResize, WindowFocus, WindowLostFocus,
		WindowMoved, AppTick, AppUpdate, AppRender,
		KeyPressd, KeyReleased, MouseButtonPressed, 
		MouseButtonReleased, MouseMoved, MouseScrolled
	};

	// We may want to filter some events according to event types
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication	= BIT(0),
		EventCategoryInput			= BIT(1),
		EventCategoryKeyboard		= BIT(2),
		EventCategoryMouse			= BIT(3),
		EventCategoryMouseButton	= BIT(4)
	};

// What is this?!
#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
								virtual EventType GetEventType() const override { return GetStaticType(); }\
								virtual const char *GetName() const override { return #type; }

	// Interface
	class ELK_API Event
	{
		friend class EventDispatcher;

	public:
		virtual EventType GetEventType() const = 0;
		virtual const char *GetName() const = 0;
		virtual std::string ToString() const { return GetName(); }
		virtual int GetCategoryFlags() const = 0;

		bool IsInCategory(EventCategory category)
		{
			return GetCategoryFlags() & category;
		}

	protected:
		bool m_Handled = false;
	};
}

