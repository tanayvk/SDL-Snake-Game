#include <iostream>
#include "../Headers/Application.hpp"
#include "../Headers/Timer.hpp"
#include "../Headers/Game.hpp"

using namespace std;

///////////////////////////////////////////////////
//               The Main Function               //
///////////////////////////////////////////////////

int main(int argc, char* argv[])
{
	// The timer for calculating the delta time
	Timer* mainTimer = new Timer();
	mainTimer->Start();

	// Initialize the game
	Game* game = new Game();
	game->Init();

	cout << "initialization took " << mainTimer->GetTime() << " milliseconds." << endl;
	
	// The game loop
	while (game->IsRunning())
	{
		game->HandleEvents();
		game->Update(mainTimer->Refresh()); // pass the delta time to the update function
		game->Render();
	}

	// Clean the game and quit
	game->Clean();

	return 0;
}


