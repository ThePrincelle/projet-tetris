#include "sprite.h"

// Constructors
Sprite::Sprite()
{

}

Sprite::Sprite(Surface *surface, SDL_Rect clipRect)
: m_Surface(surface), m_Rect(clipRect)
{

}

Sprite::Sprite(Surface *surface, int x, int y, int w, int h)
: m_Surface(surface), m_Rect({x, y, w, h})
{

}

// Getters
Surface *Sprite::GetSurface()
{
    return m_Surface;
}

SDL_Surface *Sprite::GetSDLSurface()
{
    return m_Surface->GetSDLSurface();
}

const SDL_Rect *Sprite::GetRect()
{
    return &m_Rect;
}

const int Sprite::GetWidth()
{
    return m_Rect.w;
}

const int Sprite::GetHeight()
{
    return m_Rect.h;
}

const Vec2 Sprite::GetCenter()
{
    return Vec2(m_Rect.w / 2, m_Rect.h / 2);
}