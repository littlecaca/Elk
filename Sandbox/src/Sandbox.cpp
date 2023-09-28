#include <iostream>
#include <Hazel.h>

/*
 * The Entry Point has been put into the engine side.
 */

class Sandbox : public Hazel::Application {
public:
	Sandbox() { }

	~Sandbox() override { }
	void Run() override 
	{
		std::cout << "Welcome Sandbox Application!" << std::endl;
	}
};


Hazel::Application* Hazel::CreateApplication() {
	return new Sandbox();
}