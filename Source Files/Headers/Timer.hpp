#pragma once
#include <SDL.h>

class Timer
{
public:
	// Start the timer
	void Start();
	// Pause the timer
	void Pause();
	// Stop the timer
	int Stop();
	// Refrest the timer
	int Refresh();
	// Get the time elsapsed by the timer
	int GetTime();

	Timer();

private:
	// The time seems to have started
	int myStartTime;
	// The time elapsed when the timer was paused
	int myPauseTime;
	// Is the timer running?
	bool myRunning;
	// Is the timer paused?
	bool myPaused;
};

