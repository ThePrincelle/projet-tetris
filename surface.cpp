#include "surface.h"

// Constructors
Surface::Surface() : m_Surface(nullptr)
{

}

Surface::Surface(std::string sprintFileName)
{
    m_Surface = SDL_LoadBMP(sprintFileName.c_str());
    SDL_SetColorKey(m_Surface, true, 0);
}

Surface::Surface(SDL_Surface *surface)
{
    m_Surface = surface;
    SDL_SetColorKey(m_Surface, true, 0);
}

// Getters
int Surface::GetWidth()
{
    return m_Surface->w;
}

int Surface::GetHeight()
{
    return m_Surface->h;
}

SDL_Surface *Surface::GetSDLSurface()
{
    return m_Surface;
}








