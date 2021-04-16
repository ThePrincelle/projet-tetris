
#include "surface.h"
#include "piece.h"
#include "timer.h"
#include "pieceBag.h"
#include "window_surface.h"
#include <string>
#include <unordered_map>

#ifndef _MENU_H
#define _MENU_H


using namespace std;
class Menu {
    SDL_Window *m_Window;
    WindowSurface *m_WinSurf;
    Surface *m_Sheet;
    Surface *m_Sheet_Logo;
    const Uint8 *keys;

    unordered_map<string, Sprite> m_Sprites;
    bool b_Quit;
public:

    // Constructor
    Menu() : m_Window(nullptr), m_WinSurf(nullptr), m_Sheet(nullptr), m_Sheet_Logo(nullptr), keys(nullptr), b_Quit(false){}
    ~Menu();

    // Actions
    void Init();
    void Loop();

private:
    void Draw(double dt);
    void Input();
};


#endif //_MENU_H
