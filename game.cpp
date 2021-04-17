
#include <iostream>
#include "game.h"

// Inits the UI of the game
void Game::Init()
{
    m_Board = Board::GetInstanceBoard(m_Id);
    m_Window =
            SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    m_Sheet = new Surface("./textures.bmp");
    auto background = new Surface("./background.bmp");
    m_Sprites = {
            //{"background", Sprite(background, {0, 0, 600, 600})},
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"BlockRed", Sprite(m_Sheet, {7, 3, 21, 21})},
            {"BlockOrange", Sprite(m_Sheet, {29, 3, 21, 21})},
            {"BlockYellow", Sprite(m_Sheet, {51, 3, 21, 21})},
            {"BlockGreen", Sprite(m_Sheet, {73, 3, 21, 21})},
            {"BlockLBlue", Sprite(m_Sheet, {95, 3, 21, 21})},
            {"BlockDBlue", Sprite(m_Sheet, {117, 3, 21, 21})},
            {"BlockMagenta", Sprite(m_Sheet, {139, 3, 21, 21})},
            {"BlockGray", Sprite(m_Sheet, {161, 3, 21, 21})},
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
    m_pieceBag = PieceBag(m_PieceFactory, m_Window);

    m_CurrentPiece = m_pieceBag.GetNextPiece();
    m_CurrentPiece->SetPosition(startPos);
    m_CurrentPiece->SetVelocity(startVel);
    m_CurrentPiece->SetStatic(false);
}

// Handles inputs from the User
void Game::Input()
{
    keys = SDL_GetKeyboardState(nullptr);
    //Vec2 increaseVel = Vec2(1,m_Force);

    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);

    // Quit Game
    if ((b_Quit |= (keys[SDL_SCANCODE_ESCAPE] != 0)))
        return;

    // Center Block
    if (keys[SDL_SCANCODE_SPACE]) {
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
    else if (keys[SDL_SCANCODE_UP])
    {
        m_CurrentPiece->RotateRight();
    }
    /*else if (keys[SDL_SCANCODE_])
    {
        m_CurrentPiece->RotateLeft();
    }*/
    else if (keys[SDL_SCANCODE_RIGHT])
    {
        if(((w/2.0 + 21.0 * 6.0)-1.2) > (int)round(m_CurrentPiece->GetMaxRightPosition().x + 21))
            m_CurrentPiece->MoveRight(m_Board,w,h);
    }
    else if (keys[SDL_SCANCODE_LEFT])
    {
        if(((w/2.0 - 21.0 * 4.0)-1.2) < (int)round(m_CurrentPiece->GetMaxLeftPosition().x - 21))
            m_CurrentPiece->MoveLeft(m_Board, w,h);

    }
    else
    {
        if(m_Sprint) {
            if(!m_CurrentPiece->IsStatic())
                m_CurrentPiece->StopSprint();// disable sprint
            m_Sprint = false;
        }
    }
}

// Draws the UI
void Game::Draw(double dt)
{
    //Init Window size
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);

    //Draw Back Ground
    m_WinSurf->DrawBackground();

    // --- Draw playGround --- Begin
    Vec2 beginLimitLeft = Vec2((float)((w/2.0 - 21.0 * 5.0)-1.2), h-20*21 -  3*21);
    Vec2 beginLimitRight = Vec2((float)((w/2.0 + 21.0 * 6.0)-1.2), h-20*21 - 3*21);
    Vec2 beginLimitBottom = Vec2((float)((w/2.0 - 21.0 * 5.0)-1.2), h - 2*21 );
    m_WinSurf->Paint(m_Sprites["BlockGray"],beginLimitLeft , 1, 20*21);
    m_WinSurf->Paint(m_Sprites["BlockGray"],beginLimitRight , 1, 20*21);
    m_WinSurf->Paint(m_Sprites["BlockGray"],beginLimitBottom , 11*21, 1);
    // --- Draw playGround --- End

    //Current Piece Action
    b_End = m_CurrentPiece->Fall(dt, m_Board, w, h);
    if(m_CurrentPiece->IsStatic())
    {
       m_Sprint = false;
       m_CurrentPiece =  m_pieceBag.GetNextPiece();
       m_PieceFactory->ReloadPosition(m_CurrentPiece);
       m_PieceFactory->ReloadVelocity(m_CurrentPiece,m_Force);
       m_CurrentPiece->SetStatic(false);
    }

    //All Piece action
    m_PieceFactory->DrawAllPiece(m_WinSurf);
}

// Main Loop for Game
void Game::Loop()
{
    while (!b_Quit || !b_End) {
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

// Destroy Game
Game::~Game()
{
    delete m_WinSurf;
    delete m_Sheet;
    m_Sprites.clear();
    SDL_Quit();
}