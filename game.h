
#include "surface.h"
#include "block.h"
#include "timer.h"
#include "window_surface.h"
#include <string>
#include <unordered_map>

#ifndef _GAME_H
#define _GAME_H


using namespace std;
class Game {
    SDL_Window *m_Window;
    WindowSurface *m_WinSurf;
    Surface *m_Sheet;
    const Uint8 *keys;
    Block m_Block;
    float m_Force;
    int m_Sprint;

    unordered_map<string, Sprite> m_Sprites;
    bool b_Quit;

public:

    // Constructor
    Game() : m_Window(nullptr), m_WinSurf(nullptr), m_Sheet(nullptr) ,keys(nullptr), b_Quit(false), m_Force(1), m_Sprint(false){}
    ~Game();

    // Actions
    void Init();
    void Loop();

private:
    void Draw(double dt);
    void Input();
};


#endif //_GAME_H
