#include <SDL.h>
#include <iostream>
#include "game.h"
#include "menu.h"

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        return 1;
    }

    Game g = Game(1);

	g.Init();
	g.Loop();

	//Menu m;

    //m.Init();
    //m.Loop();

    SDL_Quit();
}
