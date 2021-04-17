#include <SDL.h>
#include <iostream>
#include "game.h"
#include "menu.h"

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Menu m;

    m.Init();
    int next_step = m.Loop();

    if (next_step == 1) {
        Game g = Game(1);
        g.Init();
        g.Loop();
    } else if (next_step == 2) {
        Game g = Game(2);
        g.Init();
        g.Loop();
    } else {
        SDL_Quit();
    }
}