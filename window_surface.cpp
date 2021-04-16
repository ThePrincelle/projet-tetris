#include "window_surface.h"

// Constructors
WindowSurface::WindowSurface() : Surface()
{

}

/*WindowSurface::WindowSurface(SDL_Window *win) : m_Win(win), Surface()
{
    m_Surface = SDL_GetWindowSurface(m_Win);
}*/

WindowSurface::WindowSurface(SDL_Window *win, Sprite &backgroundSprite)
: m_Win(win), m_background(backgroundSprite), Surface()
{
    m_Surface = SDL_GetWindowSurface(m_Win);
}

// Getters
SDL_Window *WindowSurface::GetWin()
{
    return m_Win;
}

Sprite WindowSurface::GetBackGround()
{
    return m_background;
}

// Actions
void WindowSurface::DrawBackground()
{
    SDL_Rect dest = {0, 0, 0, 0};

    for (int j = 0; j < GetHeight(); j += m_background.GetHeight()) {
        for (int i = 0; i < GetWidth(); i += m_background.GetWidth()) {
            dest.x = i;
            dest.y = j;
            SDL_BlitSurface(m_background.GetSDLSurface(),
                            m_background.GetRect(), GetSDLSurface(), &dest);
        }
    }

}

void WindowSurface::Paint(Sprite &sprite, Vec2& position)
{
    SDL_Rect dst = {int(position.x), int(position.y), 0, 0};
    SDL_BlitSurface(m_background.GetSDLSurface(), sprite.GetRect(),
                    GetSDLSurface(), &dst);
}

void WindowSurface::Paint(Sprite &sprite, Vec2& position, float w, float h)
{
    SDL_Rect dst = {int(position.x), int(position.y), 0, 0};
    for (int j = 0; j < GetHeight() && j <= h; j += sprite.GetHeight()) {
        for (int i = 0; i < GetWidth() && i <= w; i += sprite.GetWidth()) {
            dst.x = int(position.x)+i;
            dst.y = int(position.y)+j;
            SDL_BlitSurface(m_background.GetSDLSurface(),
                            sprite.GetRect(), GetSDLSurface(), &dst);
        }
    }
}