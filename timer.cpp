#include "timer.h"

Timer *Timer::s_Instance = nullptr;

// Constructors
Timer::Timer()
{
    m_Now = SDL_GetPerformanceCounter();
}

// Getters
double Timer::GetDeltaTime()
{
    return m_DeltaTime;
}

// Actions
void Timer::Tick()
{
    m_LastTime = m_Now;
    m_Now = SDL_GetPerformanceCounter();
    m_DeltaTime = (double)((m_Now - m_LastTime) / (double)SDL_GetPerformanceFrequency());
}
