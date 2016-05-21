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
	myScreenPixelMap->AddColor("Snake", 0x00bbbb);
	myScreenPixelMap->AddColor("Orange", 0xF7A00A);
	myScreenPixelMap->AddColor("Green", 0x27C432);
	
	// The position of the snake object at start
	vector<Position> snakePosition;
	snakePosition.push_back(Position(7, 6));
	snakePosition.push_back(Position(6, 6));
	snakePosition.push_back(Position(5, 6));
	snakePosition.push_back(Position(4, 6));
	snakePosition.push_back(Position(3, 6));

	// Create the snake object
	mySnake = new Snake(snakePosition, Snake::Right);

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
		else if (e == Application::UpArrow && (mySnake->GetDirection() != Snake::Down))
			mySnake->ChangeDirection(Snake::Up);
		else if (e == Application::DownArrow && (mySnake->GetDirection() != Snake::Up))
			mySnake->ChangeDirection(Snake::Down);
		else if (e == Application::LeftArrow && (mySnake->GetDirection() != Snake::Right))
			mySnake->ChangeDirection(Snake::Left);
		else if (e == Application::RightArrow && (mySnake->GetDirection() != Snake::Left))
			mySnake->ChangeDirection(Snake::Right);
	}
}

void Game::Update(int deltaTime)
{
	snakeUpdateTimer += deltaTime;
	
	int snakeUpdate = snakeUpdateTimer / snakePixelTime;
	for (int i = 0; i < snakeUpdate; i++)
	{
		cout << ++counter << endl;
		if (counter == 6)
			cout << "yup" << endl;
		mySnake->MoveAhead();
		snakeUpdateTimer = 0;
	}

	UpdatePixelMap();
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
	// Initialize the snake update timer
	snakeUpdateTimer = 0;
}

void Game::UpdatePixelMap()
{
	/* Draw the snake object to the pixel map */

	// Clean the pixel map
	myScreenPixelMap->Clean();

	// Get the position of the snake
	vector<Position> snakePosition = mySnake->GetPosition();

	// Draw each piece one by one
	for (int i = 0; i < snakePosition.size(); i++)
	{
		// Get the position of the current piece
		Position position = snakePosition[i];
		myScreenPixelMap->CellSetColor(position.x, position.y, "Snake");
	}
}
