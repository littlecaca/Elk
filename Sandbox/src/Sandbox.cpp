#include "Elk.h"
#include "Elk/Input.h"
#include <imgui/imgui.h>
/*
 * The Entry Point has been put into the engine side.
 */

class ExampleLayer : public Elk::Layer
{
public:
	ExampleLayer() : Layer("Example")
	{
	}

	void OnUpdate() override
	{
		//ELK_INFO("ExampleLayer::OnUpdate");
	}

	void OnRenderImgui() override
	{
	}

	void OnEvent(Elk::Event &event) override
	{
		if (event.GetEventType() == Elk::EventType::KeyPressed)
		{
			Elk::KeyPressedEvent &e = (Elk::KeyPressedEvent &)event;
			ELK_WARN("{0} is pressed", (char)e.GetKeycode());
		}
	}
};



class Sandbox : public Elk::Application {
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox() override { }
};


Elk::Application* Elk::CreateApplication() {
	return new Sandbox();
}