#include <Elk.h>
#include "Elk/Events/ApplicationEvent.h"

/*
 * The Entry Point has been put into the engine side.
 */

class Sandbox : public Elk::Application {
public:
	Sandbox() { }

	~Sandbox() override { }
};


Elk::Application* Elk::CreateApplication() {
	return new Sandbox();
}