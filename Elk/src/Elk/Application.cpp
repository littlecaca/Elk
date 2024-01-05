#include <iostream>
#include "Application.h"

namespace Elk {
	Application::Application() {};
	void Application::Run() {
<<<<<<< HEAD
		std::cout << "Elk engine start!" << std::endl;
=======
		MouseMovedEvent move(123, 21);
		
		ELK_CORE_ERROR("Welcom to the Elk Game Engine!");
		ELK_CORE_TRACE(move.ToString());

		
>>>>>>> 9614ee7 (Add the precompiled header)
	};
	Application::~Application() {};
}