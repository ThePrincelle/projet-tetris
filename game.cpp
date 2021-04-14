
#include "game.h"

void Game::Init()
{
    m_Window =
            SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    /**m_Sheet = new Surface("./sprites.bmp");
    m_Sprites = {
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"Block", Sprite(m_Sheet, {0, 96, 24, 24})},
    };**/
    m_Sheet = new Surface("./sprites-Tetris.bmp");
    m_Sprites = {
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"Block", Sprite(m_Sheet, {4, 3, 24, 24})},
    };
    m_WinSurf = new WindowSurface(m_Window, m_Sprites["background"]);
    b_Quit = false;

    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    m_Block.SetPosition(Vec2(w / 2, h / 2));
    m_Block.SetVelocity(Vec2(0, 24));
}

void Game::Input()
{
    keys = SDL_GetKeyboardState(NULL);

    // Quit Game
    if ((b_Quit |= (keys[SDL_SCANCODE_ESCAPE] != 0)))
        return;

    // Center Block
    if (keys[SDL_SCANCODE_SPACE]) {
        int w, h;
        SDL_GetWindowSize(m_Window, &w, &h);
        m_Block.SetPosition(Vec2(w / 2 - m_Sprites["Block"].GetWidth() / 2,
                                 h / 2 - m_Sprites["Block"].GetHeight() / 2));
        // TODO: Replace 3 lines above with one line below
        // m_Block.SetPosition(m_Window.GetCenter() -
        // m_Sprites["Block"].GetCenter());
    }
    else if (keys[SDL_SCANCODE_DOWN])
    {
        if(!m_Sprint) {
            m_Block.MultiplyForce(Vec2(1, 10));// unable sprint
            m_Sprint = true;
        }

    }
    else
    {
        if(m_Sprint) {
            m_Block.MultiplyForce(Vec2(1, 0.1));// disable sprint
            m_Sprint = false;
        }
    }
}

void Game::Draw(double dt)
{
    m_WinSurf->DrawBackground();

    m_WinSurf->Paint(m_Sprites["Block"], m_Block.GetPosition());

    m_Block.Move(dt);

    // collision bord
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    if (m_Block.GetPosition().y > (h - 25))
        m_Block.SetVelocity(Vec2(0, 0));

    if(m_Block.GetPosition().y < 1) {
        //End game
    }
}

void Game::Loop()
{
    while (!b_Quit) {
        Timer::GetInstance()->Tick();

        // TODO: Change Event Handling
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                b_Quit = true;
                break;
            default:
                break;
        }

        Input();

        Draw(Timer::GetInstance()->GetDeltaTime());

        // TODO: Change window updating
        // m_Window->Update();
        SDL_UpdateWindowSurface(m_Window);
    }
}

Game::~Game()
{
    delete m_WinSurf;
    delete m_Sheet;
    m_Sprites.clear();
    SDL_Quit();
}