#pragma once
class Application
{
public:
	// Initialize the game
	bool Init();
	// Handle events
	void HandleEvents();
	// Update the game
	void Update(int deltaTime);
	// Is the game running?
	bool IsRunning() { return myRunning; }

	Application();
	~Application();
private:
	// Is the game running?
	bool myRunning;
};

