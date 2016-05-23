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
	myScreenPixelMap->AddColor("Snake", 0x0085CC);
	myScreenPixelMap->AddColor("SnakeHead", 0x00A7FF);
	myScreenPixelMap->AddColor("Food", 0xF7A00A);
	
	// The position of the snake object at start
	vector<Position> snakePosition;
	snakePosition.push_back(Position(12, 6));
	snakePosition.push_back(Position(11, 6));
	snakePosition.push_back(Position(10, 6));
	snakePosition.push_back(Position(9, 6));
	snakePosition.push_back(Position(8, 6));
	snakePosition.push_back(Position(7, 6));
	snakePosition.push_back(Position(6, 6));
	snakePosition.push_back(Position(5, 6));
	snakePosition.push_back(Position(4, 6));
	snakePosition.push_back(Position(3, 6));

	// Create the snake object
	mySnake = new Snake(snakePosition, Snake::Right);

	// Start the snake timer
	mySnakeMovementTimer = new Timer();
	mySnakeMovementTimer->Start();

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
		else if (e == Application::UpArrow)
			mySnake->ChangeDirection(Snake::Up);
		else if (e == Application::DownArrow)
			mySnake->ChangeDirection(Snake::Down);
		else if (e == Application::LeftArrow)
			mySnake->ChangeDirection(Snake::Left);
		else if (e == Application::RightArrow)
			mySnake->ChangeDirection(Snake::Right);
	}
}

void Game::Update(int deltaTime)
{
	// Calculate the number of times the snake has to move
	int snakeMoves = mySnakeMovementTimer->GetTime() / mySnakePixelTime;

	// Should the snake move?
	if (snakeMoves > 0)
	{
		// Refresh the timer	
		mySnakeMovementTimer->Refresh();

		// Move the snake ahead
		for (int i = 0; i < snakeMoves; i++)
		{
			mySnake->MoveAhead();
			
			if (mySnake->IsOverlapping())
			{
				cout << "game over" << endl;
			}
		}
	}

	if (!UpdatePixelMap())
	{
		cout << "game over" << endl;
	}
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

Game::Game()
{
}

bool Game::UpdatePixelMap()
{
	/* Draw the snake object to the pixel map */

	// Clean the pixel map
	myScreenPixelMap->Clean();

	// Get the position of the snake
	vector<Position> snakePosition = mySnake->GetPosition();

	// Draw the snake head
	if (!(myScreenPixelMap->CellSetColor(snakePosition[0].x, snakePosition[0].y, "SnakeHead")))
		return false;

	// Draw each piece one by one
	for (int i = 1; i < snakePosition.size(); i++)
	{
		// Get the position of the current piece
		Position position = snakePosition[i];
		myScreenPixelMap->CellSetColor(position.x, position.y, "Snake");
	}
}
