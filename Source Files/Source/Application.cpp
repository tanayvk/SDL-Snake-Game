#include "..\Headers\Application.hpp"

// Singleton Implementation
Application * Application::myInstance = NULL;
Application * Application::Get()
{
	if (myInstance == NULL)
		myInstance = new Application();
	return myInstance;
}

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


void Application::ClearRenderer()
{
	// Clear the main renderer
	SDL_RenderClear(myRenderer);
}

void Application::PresentRenderer()
{
	// Present the main renderer to the screen
	SDL_RenderPresent(myRenderer);
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
	int b = (color >> 0) & 0xFF;

	// Set the draw color
	SDL_SetRenderDrawColor(myRenderer, r, g, b, alpha);

	return true;
}

Application::Application()
{
}