#pragma once

#include <Elk/Core/Core.h>
#include <Elk/Events/Event.h>

namespace Elk
{
	class ELK_API Layer
	{
	public:
		Layer(const std::string &name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event &event) {}
		virtual void OnRenderImgui() {}


		inline const std::string &GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};
}
