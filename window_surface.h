#include <SDL.h>
#include "surface.h"
#include "sprite.h"
#include "vec2.h"

#ifndef _WINDOW_SURFACE_
#define _WINDOW_SURFACE_


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
        void Paint(Sprite &sprite, Vec2& position);
        void Paint(Sprite &sprite, Vec2& position, float w, float h);
};

#endif