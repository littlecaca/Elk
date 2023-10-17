#include <iostream>
#include <Elk.h>

/*
 * The Entry Point has been put into the engine side.
 */

class Sandbox : public Elk::Application {
public:
	Sandbox() { }

	~Sandbox() override { }
	void Run() override 
	{
		std::cout << "Welcome to Sandbox Application!" << std::endl;
	}
};


Elk::Application* Elk::CreateApplication() {
	return new Sandbox();
}