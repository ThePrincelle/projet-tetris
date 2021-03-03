
#include <SDL.h>
#include <string>

#ifndef _SURFACE_H_
#define _SURFACE_H_

class Sprite;

class Surface {
    protected:
        SDL_Surface *m_Surface;

    public:
        // Constructors
        Surface();
        Surface(std::string sprintFileName);
        Surface(SDL_Surface *surface);

        // Actions
        int GetWidth();
        int GetHeight();
        SDL_Surface *GetSDLSurface();
};

#endif