#pragma once


#ifdef ELK_PLATFORM_WINDOWS

extern Elk::Application* Elk::CreateApplication();

int main(int argc, char* argv[])
{
	Elk::Log::Init();
	
	//Elk::MouseMovedEvent moved_event{34, 12};
	//std::cout << moved_event.ToString() << std::endl;


	std::shared_ptr<Elk::Application> app(Elk::CreateApplication());
	app->Run();

	return 0;
}

#else
	#error Elk only support Windows!
#endif
