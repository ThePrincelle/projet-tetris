
#include <iostream>
#include "menu.h"

void Menu::Init()
{
    m_Window =
            SDL_CreateWindow("Tetris - Welcome", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 800, 350, SDL_WINDOW_SHOWN);
    m_Sheet = new Surface("./textures.bmp");
    //m_Sheet = new Surface("./background.bmp");
    m_Sprites = {
            //{"background", Sprite(background, {0, 0, 600, 600})},
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"logo", Sprite(m_Sheet, {281, 0, 365, 110})},
            {"solo", Sprite(m_Sheet, {531, 186, 115, 35})},
            {"ia", Sprite(m_Sheet, {588, 221, 58, 35})},
            {"1v1", Sprite(m_Sheet, {562, 151, 84, 35})}
    };

    m_WinSurf = new WindowSurface(m_Window, m_Sprites["background"]);

    b_Quit = false;
}

void Menu::Input()
{
    keys = SDL_GetKeyboardState(nullptr);
    //Vec2 increaseVel = Vec2(1,m_Force);

    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);

    // Quit Game
    if ((b_Quit |= (keys[SDL_SCANCODE_ESCAPE] != 0)))
        return;

}

void Menu::Draw(double dt)
{
    //Init Window size
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);

    //Draw Back Ground
    m_WinSurf->DrawBackground();

    // --- Draw title --- Begin
    Vec2 position = Vec2((float)((w/2)-(m_Sprites["logo"].GetWidth()/2)-20), 60);
    m_WinSurf->Paint(m_Sprites["logo"], position);
    // --- Draw title --- End

    // --- Draw Solo --- Begin
    Vec2 position_solo = Vec2((float)((w/3)-(m_Sprites["solo"].GetWidth()/2)), 240);
    m_WinSurf->Paint(m_Sprites["solo"], position_solo);
    // --- Draw Solo --- End

    // --- Draw IA --- Begin
    Vec2 position_ia = Vec2((float)((w/3)*2-(m_Sprites["ia"].GetWidth()/2)), 240);
    m_WinSurf->Paint(m_Sprites["ia"], position_ia);
    // --- Draw IA --- End

    // --- Draw 1V1 --- Begin
    //Vec2 position_1v1 = Vec2((float)((w/6)*5-(m_Sprites["1v1"].GetWidth()/2)), 240);
    //m_WinSurf->Paint(m_Sprites["1v1"], position_1v1);
    // --- Draw 1V1 --- End


}

void Menu::Loop()
{

    while (!b_Quit) {
        Timer::GetInstance()->Tick();

        // TODO: Change Event Handling
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            Input();
        }
        switch (event.type) {
            case SDL_QUIT:
                b_Quit = true;
                break;
            default:
                break;
        }

        Draw(Timer::GetInstance()->GetDeltaTime());

        // TODO: Change window updating
        // m_Window->Update();
        SDL_UpdateWindowSurface(m_Window);
    }
}

Menu::~Menu()
{
    delete m_WinSurf;
    delete m_Sheet;
    SDL_Quit();
}