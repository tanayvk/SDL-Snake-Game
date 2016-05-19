#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include "PixelMap.hpp"

using namespace std;

class Application
{
public:
	// Initialize the application
	bool Init();

	// Clear the renderer
	bool ClearRenderer();
	// Present the renderer
	bool PresentRenderer();
	// Set the color of the renderer
	bool SetDrawColor(int color, int alpha);

	// Draw a rectangle to the screen
	void DrawRect(int x, int y, int width, int height);
	// Draw a rectangle to the screen
	void DrawFilledRect(int x, int y, int width, int height);

	// Get the width of the screen
	int GetScreenWidth() { return myScreenWidth; }
	// Get the height of the screen
	int GetScreenHeight() { return myScreenHeight; }

	// Return the singleton object
	static Application* Get();

	~Application();
private:
	// The main window of the game
	SDL_Window* myWindow;
	// The renderer of the main window
	SDL_Renderer* myRenderer;

	// The width of the window
	const int myScreenWidth = 800;
	// The height of the window
	const int myScreenHeight = 800;

	// Private Constructor
	Application();
	// The singleton instance
	static Application* instance;
};
