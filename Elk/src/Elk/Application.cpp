#include <iostream>
#include "Application.h"

namespace Elk {
	Application::Application() {};
	void Application::Run() {

		MouseMovedEvent move(123, 21);
		
		ELK_CORE_ERROR("Welcom to the Elk Game Engine!");
		ELK_CORE_TRACE(move.ToString());

	};
	Application::~Application() {};
}