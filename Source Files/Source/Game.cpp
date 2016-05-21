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
	myScreenPixelMap = new PixelMap(50, 50);

	// Add some colors to the pixel map
	myScreenPixelMap->AddColor("Blue", 0x00bbbb);
	myScreenPixelMap->AddColor("Orange", 0xF7A00A);
	myScreenPixelMap->AddColor("Green", 0x27C432);

	return true;
}

void Game::HandleEvents()
{
	// The event
	Application::Event e;

	// Loop through the event queue
	while (e = app->PollEvent())
	{
		if (e == Application::Quit)
			// The user closed the window, quit
			myRunning = false;
	}
}

void Game::Update(int deltaTime)
{
	cout << deltaTime << endl;
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
	// Delete the game objects
	delete myScreenPixelMap;
	delete app;
}
