
#include "game.h"

void Game::Init()
{
    m_Window =
            SDL_CreateWindow("TP1 - Nicolas LAFORET", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, 600, 600, SDL_WINDOW_SHOWN);
    m_Sheet = new Surface("./sprites.bmp");
    m_Sprites = {
            {"background", Sprite(m_Sheet, {0, 128, 96, 128})},
            {"ball", Sprite(m_Sheet, {0, 96, 24, 24})},
    };
    m_WinSurf = new WindowSurface(m_Window, m_Sprites["background"]);
    b_Quit = false;

    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    m_Ball.SetPosition(Vec2(w / 2, h / 2));
    m_Ball.SetVelocity(Vec2(40, 25));
}

void Game::Input()
{
    keys = SDL_GetKeyboardState(NULL);

    // Quit Game
    if ((b_Quit |= (keys[SDL_SCANCODE_ESCAPE] != 0)))
        return;

    // Center Ball
    if (keys[SDL_SCANCODE_SPACE]) {
        int w, h;
        SDL_GetWindowSize(m_Window, &w, &h);
        m_Ball.SetPosition(Vec2(w / 2 - m_Sprites["ball"].GetWidth() / 2,
                                 h / 2 - m_Sprites["ball"].GetHeight() / 2));
        // TODO: Replace 3 lines above with one line below
        // m_Ball.SetPosition(m_Window.GetCenter() -
        // m_Sprites["ball"].GetCenter());
    }

    // Ball Movement
    m_Ball.AddForce(
            Vec2(0.2 * keys[SDL_SCANCODE_RIGHT] - 0.2 * keys[SDL_SCANCODE_LEFT],
                  0.2 * keys[SDL_SCANCODE_DOWN] - 0.2 * keys[SDL_SCANCODE_UP]));
}

void Game::Draw(double dt)
{
    m_WinSurf->DrawBackground();

    m_WinSurf->Paint(m_Sprites["ball"], m_Ball.GetPosition());

    m_Ball.Move(dt);

    // collision bord
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    if ((m_Ball.GetPosition().x < 1) || (m_Ball.GetPosition().x > (w - 25)))
        m_Ball.MultiplyForce(Vec2(-1, 1));
    if ((m_Ball.GetPosition().y < 1) || (m_Ball.GetPosition().y > (h - 25)))
        m_Ball.MultiplyForce(Vec2(1, -1));
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