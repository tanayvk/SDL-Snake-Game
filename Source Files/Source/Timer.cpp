#include "..\Headers\Timer.hpp"


void Timer::Start()
{
	// Is the timer running and not paused?
	if (myRunning && !myPaused)
	{
		// Yes, quit
		return;
	}

	// Is the timer paused?
	if (myPaused == true)
	{
		// Yes, unpause it
		myPaused = false;
		// Reset the start time
		myStartTime = SDL_GetTicks() - myPauseTime;
	}
	else
	{
		// No, start a fresh timer
		myStartTime = SDL_GetTicks();
		// The timer is now running
		myRunning = true;
	}
}

void Timer::Pause()
{
	// Is the timer stopped or already paused?
	if (!myRunning || myPaused)
	{
		// Yes, quit
		return;
	}

	// Set the pause time to the time elapsed
	myPauseTime = SDL_GetTicks() - myStartTime;
	// The timer is now paused
	myPaused = true;

}

int Timer::Stop()
{
	// Store the time elapsed
	int time = GetTime();

	// The timer is now stopped
	myRunning = false;

	// Return the time elapsed
	return time;
}

int Timer::Refresh()
{
	// Stop the timer and store the time elapsed
	int time = Stop();
	
	// Start the timer again
	Start();

	// Return the time elapsed
	return time;
}

int Timer::GetTime()
{
	if (myRunning)
	{
		// Calculate the time elapsed
		return SDL_GetTicks() - myStartTime;
	}

	// The timer was not running!
	return 0;
}

Timer::Timer()
{
	// The timer is not running at start
	myRunning = false;
	// The timer was not paused at any time
	myPauseTime = 0;
}
