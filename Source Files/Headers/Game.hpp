#pragma once
#include "PixelMap.hpp"
#include "Application.hpp"
#include <SDL.h>

class Game
{
public:
	// Initialize the game
	bool Init();
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


	Game();
	~Game();
private:
	// Is the game running?
	bool myRunning;
	// The map of the screen
	PixelMap* myScreenPixelMap;
	// The reference to the application
	Application* app;
};

