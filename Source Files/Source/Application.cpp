#include "..\Headers\Application.hpp"

bool Application::Init()
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

Application::Event Application::PollEvent()
{
	SDL_Event e;

	if (SDL_PollEvent(&e) == NULL)
		return None;

	// Return only those events which are being checked
	switch (e.type)
	{
	case SDL_QUIT: 
		return Quit;
	case SDL_KEYDOWN:
		if (e.key.keysym.sym == SDLK_UP)
			return UpArrow;
		else if (e.key.keysym.sym == SDLK_DOWN)
			return DownArrow;
		else if (e.key.keysym.sym == SDLK_LEFT)
			return LeftArrow;
		else if (e.key.keysym.sym == SDLK_RIGHT)
			return RightArrow;
		else
			return Unknown;
	default:
		return Unknown;
	}
}

bool Application::ClearRenderer()
{
	// Does the renderer exist?
	if (myRenderer == NULL)
	{
		// No, report and quit
		cout << "the renderer has not yet been created" << endl;
		return false;
	}

	// Clear the main renderer
	SDL_RenderClear(myRenderer);

	return true;
}

bool Application::PresentRenderer()
{
	// Does the renderer exist?
	if (myRenderer == NULL)
	{
		// No, report and quit
		cout << "the renderer has not yet been created" << endl;
		return false;
	}

	// Clear the main renderer
	SDL_RenderPresent(myRenderer);

	return true;
}


void Application::DrawRect(int x, int y, int width, int height)
{
	// Set the properties of the rectangle
	SDL_Rect rect = { x, y, width, height };
	// Draw the rectangle using the main renderer
	SDL_RenderDrawRect(myRenderer, &rect);
}

void Application::DrawFilledRect(int x, int y, int width, int height)
{
	// Set the properties of the rectangle
	SDL_Rect rect = { x, y, width, height };
	// Draw the rectangle using the main renderer
	SDL_RenderFillRect(myRenderer, &rect);

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
Application * Application::Get()
{
	if (instance == NULL)
		instance = new Application();

	return instance;
}

Application::~Application()
{
}
