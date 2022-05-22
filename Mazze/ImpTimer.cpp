
#include "ImpTimer.h"

ImpTimer::ImpTimer()
{
	start_tick = 0;
	pause_tick = 0;
	is_paused = false;
	is_started = false;
	pause_time = 0;
}

ImpTimer::~ImpTimer()
{

}

void ImpTimer::Start()
{
	is_started = true;
	is_paused = false;
	start_tick = SDL_GetTicks();
}

void ImpTimer::Stop()
{
	is_paused = false;
	is_started = false;
	pause_time = 0;
}

void ImpTimer::Paused()
{
	if (is_started && !is_paused)
	{
		is_paused = true;
		pause_tick = SDL_GetTicks(); //thời điểm ngưng
	}
}

void ImpTimer::Unpaused()
{
	if (is_paused)
	{
		is_paused = false;
		pause_time += (SDL_GetTicks() - pause_tick);
	}
}

bool ImpTimer::IsStarted()
{
	return is_started;
}

bool ImpTimer::IsPaused()
{
	return is_paused;
}

int ImpTimer::GetTime()
{
	return SDL_GetTicks() - start_tick - pause_time;
}