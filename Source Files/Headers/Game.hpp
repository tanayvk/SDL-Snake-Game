#pragma once
#include <iostream>
#include "Application.hpp"
#include "PixelMap.hpp"
#include <random>
#include <cmath>

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
private:
	// The reference to the application
	Application* app;
	// The map of the screen
	PixelMap* myScreenPixelMap;
	
	// Is the game running?
	bool myRunning;
};

