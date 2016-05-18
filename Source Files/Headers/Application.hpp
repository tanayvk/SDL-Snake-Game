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
	// Initialize the game
	bool Init();
	// Initialize SDL
	bool InitSDL();
	// Initialize the game objects
	bool InitGameObjects();
	// Handle events
	void HandleEvents();
	// Update the game
	void Update(int deltaTime);
	// Render the screen
	void Render();
	// Clean the resources used by the application
	void Clean();
	// Is the game running?
	bool IsRunning() { return myRunning; }

	// Draw a rectangle to the screen
	void DrawRect(int x, int y, int width, int height);
	// Set the color of the renderer
	bool SetDrawColor(int color, int alpha);

	// Get the width of the screen
	int GetScreenWidth() { return myScreenWidth; }
	// Get the height of the screen
	int GetScreenHeight() { return myScreenHeight; }

	// Return the singleton object
	static Application* get();

	~Application();
private:
	// Is the game running?
	bool myRunning;
	// The main window of the game
	SDL_Window* myWindow;
	// The renderer of the main window
	SDL_Renderer* myRenderer;
	// The map of the screen
	PixelMap* myScreenPixelMap;
	// The width of the window
	const int myScreenWidth = 1280;
	// The height of the window
	const int myScreenHeight = 720;

	// Private Constructor
	Application();
	// The singleton instance
	static Application* instance;
};
