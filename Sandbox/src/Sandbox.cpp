#include "Elk.h"

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
		ELK_INFO("ExampleLayer::OnUpdate");
	}

	void OnEvent(Elk::Event &event) override
	{
		ELK_INFO("ExampleLayer::OnEvent : {0}", event);
	}
};



class Sandbox : public Elk::Application {
public:
	Sandbox() 
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Elk::ImGuiLayer());
	}

	~Sandbox() override { }
};


Elk::Application* Elk::CreateApplication() {
	return new Sandbox();
}