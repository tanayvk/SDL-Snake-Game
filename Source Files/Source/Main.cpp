#include <iostream>
#include "../Headers/Application.hpp"
#include "../Headers/Timer.hpp"

using namespace std;

///////////////////////////////////////////////////
//               The Main Function               //
///////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	// The timer for calculating the delta time
	Timer* mainTimer = new Timer();
	mainTimer->Start();

	// Initialize the application
	Application* app = Application::get();
	app->Init();

	cout << "initialization took " << mainTimer->GetTime() << " milliseconds." << endl;
	
	// The game loop
	while (app->IsRunning())
	{
		app->HandleEvents();
		app->Update(mainTimer->Refresh()); // pass the delta time to the update function
		app->Render();
	}

	// Clean the game and quit
	app->Clean();

	return 0;
}


