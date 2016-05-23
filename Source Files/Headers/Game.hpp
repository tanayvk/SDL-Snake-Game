#pragma once
#include <iostream>
#include "Timer.hpp"
#include "Application.hpp"
#include "PixelMap.hpp"
#include "Position.hpp"
#include "Snake.hpp"
#include "Food.hpp"
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

	Game();
private:
	// Update the pixel map
	bool UpdatePixelMap();
	// Spawn new food
	void SpawnFood();

	// The reference to the application
	Application* app;
	// The map of the screen
	PixelMap* myScreenPixelMap;
	// The snake object
	Snake* mySnake;
	// The food object
	Food* myFood;
	
	// The time taken by the snake to travel one pixel
	int mySnakePixelTime = 500;
	// The timer for controlling the snake movement
	Timer* mySnakeMovementTimer;

	// Is the game running?
	bool myRunning;
};

