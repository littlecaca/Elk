#include <iostream>
#include "Application.h"

namespace Hazel {
	Application::Application() {};
	void Application::Run() {
		std::cout << "Hazel engine start!" << std::endl;
	};
	Application::~Application() {};
}