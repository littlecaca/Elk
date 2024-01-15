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

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnRenderImgui() override;
				
		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};
}