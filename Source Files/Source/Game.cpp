#include "..\Headers\Game.hpp"

bool Game::Init()
{
	// The game isn't yet running
	myRunning = false;

	// Get the application object
	app = Application::Get();

	// Initialize SDL subsystems
	if (!app->Init())
		// Error initializing SDL
		return false;

	// Initialize the game objects
	if (!InitGameObjects())
		// Error initializing game objects
		return false;

	// The game has been initialized and now running
	myRunning = true;

	return true;
}


bool Game::InitGameObjects()
{
	// Create the screen map
	myScreenPixelMap = new PixelMap(25, 25);
	myScreenPixelMap->CellSetColor(10, 5, PixelMap::Blue);
	return true;
}

void Game::HandleEvents()
{
	// The event to be handled
	SDL_Event e;

	// Loop through the event queue for handling all the queued events
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			// The user closed the window, quit
			myRunning = false;

		if (e.type == SDL_MOUSEBUTTONDOWN)
			// The user clicked on the screen

	}
}

void Game::Update(int deltaTime)
{
	
}

void Game::Render()
{
	// Clear the renderer
	app->SetDrawColor(0, 0xFF);
	app->ClearRenderer();

	// Render the map on the screen
	myScreenPixelMap->Render();

	// Present the renderer
	app->PresentRenderer();
}

void Game::Clean()
{
}


Game::Game()
{
}


Game::~Game()
{
}
