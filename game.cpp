
#include <iostream>
#include "game.h"

void Game::Init()
{
    m_Window =
            SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    m_Sheet = new Surface("./textures.bmp");
    m_Sprites = {
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"BlockRed", Sprite(m_Sheet, {7, 3, 21, 21})},
            {"BlockOrange", Sprite(m_Sheet, {29, 3, 21, 21})},
            {"BlockYellow", Sprite(m_Sheet, {51, 3, 21, 21})},
            {"BlockGreen", Sprite(m_Sheet, {73, 3, 21, 21})},
            {"BlockLBlue", Sprite(m_Sheet, {95, 3, 21, 21})},
            {"BlockDBlue", Sprite(m_Sheet, {117, 3, 21, 21})},
            {"BlockMagenta", Sprite(m_Sheet, {139, 3, 21, 21})},
    };
    m_WinSurf = new WindowSurface(m_Window, m_Sprites["background"]);
    b_Quit = false;

    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    Vec2 startPos = Vec2(w / 2 - 21, 0);
    Vec2 startVel = Vec2(0, 24);
    m_PieceFactory = PieceFactory::GetPieceFactory();
    m_PieceFactory->SetStartPos(startPos);
    m_PieceFactory->SetStartVel(startVel);
    m_PieceFactory->SetSprites(m_Sprites);

    m_CurrentPiece = m_PieceFactory->CreatePiece(TetrisPiece::S, m_Force);
}

void Game::Input()
{
    keys = SDL_GetKeyboardState(nullptr);
    Vec2 increaseVel = Vec2(1,m_Force);

    // Quit Game
    if ((b_Quit |= (keys[SDL_SCANCODE_ESCAPE] != 0)))
        return;

    // Center Block
    if (keys[SDL_SCANCODE_SPACE]) {
        int w, h;
        SDL_GetWindowSize(m_Window, &w, &h);
        m_PieceFactory->ReloadPosition(m_CurrentPiece);
        m_PieceFactory->ReloadVelocity(m_CurrentPiece,m_Force);
    }
    else if (keys[SDL_SCANCODE_DOWN])
    {
        if(!m_Sprint) {
            m_CurrentPiece->Sprint();// unable sprint
            m_Sprint = true;
        }

    }
    else
    {
        if(m_Sprint) {
            m_CurrentPiece->StopSprint();// disable sprint
            m_Sprint = false;
        }
        m_CurrentPiece->MultiplyForce(increaseVel);
    }
}

void Game::Draw(double dt)
{
    m_WinSurf->DrawBackground();

    m_CurrentPiece->SelfPaint(m_WinSurf);

    m_CurrentPiece->Move(dt);
    Vec2 stopVel = Vec2(0, 0);

    // collision bord
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    if (m_CurrentPiece->GetMaxDownPosition().y > (float)(h - 25))
        m_CurrentPiece->MultiplyForce(stopVel);

    if(m_CurrentPiece->GetMaxUpPosition().y < 1) {
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