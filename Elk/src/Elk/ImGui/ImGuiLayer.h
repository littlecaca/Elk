#pragma once

#include <Elk/Layer.h>

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
		virtual void OnEvent(Event &event);

	private:
		float m_Time = 0;
	};
}