#include <SDL.h>
#include <iostream>
#include "game.h"

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Game g;

    g.Init();
    g.Loop();

    SDL_Quit();
}
