#include "pieceBag.h"

PieceBag::PieceBag() {}

PieceBag::PieceBag(PieceFactory* pieceFactory, SDL_Window *window) : m_PieceFactory(pieceFactory), m_Window(window)
{
    m_Hand = vPiece();
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    m_SortOfPieces = vector<int>();
    InitPilePiece();

    for( int i=0; i<3; i++)
    {
        int pieceNumber = m_SortOfPieces[0];
        m_SortOfPieces.erase(m_SortOfPieces.begin());
        auto typePiece = (TetrisPiece)pieceNumber;
        m_Hand.push_back(m_PieceFactory->CreatePiece(typePiece, (w/4)*3 + 60,  20+i*86));
    }
}

Piece* PieceBag::GetNextPiece()
{
    int w, h;
    SDL_GetWindowSize(m_Window, &w, &h);
    Piece* res = m_Hand[0];
    m_Hand.erase(m_Hand.begin());

    int pieceNumber = m_SortOfPieces[0];
    m_SortOfPieces.erase(m_SortOfPieces.begin());
    if(m_SortOfPieces.empty())
    {
        InitPilePiece();
    }

    auto typePiece = (TetrisPiece)pieceNumber;

    for(Piece* temp_piece : m_Hand)
        temp_piece->Move(Vec2(0,-86),true);

    m_Hand.push_back(m_PieceFactory->CreatePiece(typePiece, (w/4)*3 + 60,20+2*86));
    return res;
}

void PieceBag::InitPilePiece()
{
    int maxPiece = TetrisPiece::Count;
    for(int i = 0; i < maxPiece; i++)
        m_SortOfPieces.push_back(i);
    shuffle(begin(m_SortOfPieces), end(m_SortOfPieces),default_random_engine(0));
}