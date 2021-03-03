#include <SDL.h>
#include "surface.h"
#include "vec2.h"

#ifndef _SPRITE_H_
#define _SPRITE_H_

class WindSurface;

class Sprite
{
    // Properties
    private:
        Surface *m_Surface;
        SDL_Rect m_Rect;

    public:

        // Constructors
        Sprite();
        Sprite(Surface *surface, SDL_Rect clipRect);
        Sprite(Surface *surface, int x, int y, int w, int h);

        // Getters
        Surface *GetSurface();
        SDL_Surface *GetSDLSurface();
        const SDL_Rect *GetRect();
        const int GetWidth();
        const int GetHeight();
        const Vec2 GetCenter();


};
#endif