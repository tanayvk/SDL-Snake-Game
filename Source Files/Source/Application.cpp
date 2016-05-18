#include "..\Headers\Application.hpp"

bool Application::Init()
{
	// The game isn't yet running
	myRunning = false;

	// Initialize SDL subsystems
	if (!InitSDL())
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

bool Application::InitSDL()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		// Error initializing SDL, report and quit
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		return false;
	}

	// Create the window for the game
	myWindow = SDL_CreateWindow("Snake Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, myScreenWidth, myScreenHeight, 0);

	if (!myWindow)
	{
		// Error creating the window, report and quit
		cout << "Error creating the window: " << SDL_GetError() << endl;
		return false;
	}

	// Create the renderer for the game window
	myRenderer = SDL_CreateRenderer(myWindow, -1, SDL_RENDERER_ACCELERATED);

	if (!myRenderer)
	{
		// Error creating the renderer, report and quit
		cout << "Error creating the renderer for the game window: " << SDL_GetError() << endl;
		return false;
	}

	cout << "initialized SDL subsystems" << endl;
	return true;
}

bool Application::InitGameObjects()
{
	// Create the screen map
	myScreenPixelMap = new PixelMap(100, 100);
	myScreenPixelMap->CellSetColor(32, 28, PixelMap::Blue);
	return true;
}

void Application::HandleEvents()
{
	// The event to be handled
	SDL_Event e;

	// Loop through the event queue for handling all the queued events
	while (SDL_PollEvent(&e))
	{
		if (e.type == SDL_QUIT)
			// The user closed the window, quit
			myRunning = false;
	}
}

void Application::Update(int deltaTime)
{
	
}

void Application::Render()
{
	// Clear the screen with black color
	SetDrawColor(0, 0xFF);
	SDL_RenderClear(myRenderer);

	// Render the map on the screen
	myScreenPixelMap->Render();
}

void Application::Clean()
{
}

void Application::DrawRect(int x, int y, int width, int height)
{
	// Set the properties of the rectangle
	SDL_Rect rect = { x, y, width, height };
	// Draw the rectangle using the main renderer
	SDL_RenderDrawRect(myRenderer, &rect);
}

bool Application::SetDrawColor(int color, int alpha)
{
	if (color > 0xFFFFFF || color < 0 || alpha > 0xFF || alpha < 0)
	{
		// Improper arguments, report and quit
		cout << "couldn't set the draw color (" << color << "," << alpha << ")" << ", improper arguments!" << endl;
		return false;
	}

	// Calculate the individual colors
	int r = (color >> 16) & 0xFF;
	int g = (color >> 8) & 0xFF;
	int b = (color >> 0) & 0xFf;

	// Set the draw color
	SDL_SetRenderDrawColor(myRenderer, r, g, b, alpha);

	return true;
}

Application::Application()
{
}

Application * Application::instance = NULL;
Application * Application::get()
{
	if (instance == NULL)
		instance = new Application();

	return instance;
}

Application::~Application()
{
}
