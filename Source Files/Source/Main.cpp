#include "../Headers/Application.hpp"
#include "../Headers/Timer.hpp"

////////////////////////////////////////////////
//				 The Main Loop                //
////////////////////////////////////////////////

int main(int argc, char* argv[])
{

	Application* app = new Application();

	// Create the main timer
	Timer* mainTimer = new Timer();
	// Start the main timer
	mainTimer->Start();
	
	// Initialize the game
	if (!app->Init())
	{
		// Error initializing
		return 1;
	}

	while (app->IsRunning())
	{
		app->HandleEvents();
		app->Update(mainTimer->Refresh());
	}

	return 0;
}
