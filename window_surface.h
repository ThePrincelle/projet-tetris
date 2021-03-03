#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_


#include <SDL.h>
#include "surface.h"
#include "sprite.h"
#include "vec2.h"

class Sprite;

class WindowSurface : public Surface
{
    // Properties
    private:
        SDL_Window *m_Win;
        Sprite m_background;

    public:

        // Constructors
        WindowSurface();
        //WindowSurface(SDL_Window *win);
        WindowSurface(SDL_Window *win, Sprite &backgroundSprite);


        //Getters
        SDL_Window *GetWin();
        Sprite GetBackGround();

        // Actions
        void DrawBackground();
        void Paint(Sprite &sprite, Vec2 position);
};

#endif