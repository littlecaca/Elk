#include <iostream>
#include <Elk.h>
#include "Elk/Events/ApplicationEvent.h"

/*
 * The Entry Point has been put into the engine side.
 */

class Sandbox : public Elk::Application {
public:
	Sandbox() { }

	~Sandbox() override { }
	void Run() override 
	{
		//Elk::MouseMovedEvent event {12, 32};
		//std::cout << event.ToString() << std::endl;
		//Elk::KeyReleasedEvent key(12);
		Elk::WindowResizeEvent ss(12, 32);
		ss.ToString();
		//ELK_TRACE(ss.ToString());
		std::cout << "Welcome to Sandbox Application!" << std::endl;
	}
};


Elk::Application* Elk::CreateApplication() {
	return new Sandbox();
}