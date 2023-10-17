#include <iostream>
#include "Application.h"

namespace Elk {
	Application::Application() {};
	void Application::Run() {
		std::cout << "Elk engine start!" << std::endl;
	};
	Application::~Application() {};
}