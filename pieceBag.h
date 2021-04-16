
#include <vector>
#include "piece.h"
#include <stack>
#include <bits/stdc++.h>

#ifndef TP1_PROGAV_PIECEBAG_H
#define TP1_PROGAV_PIECEBAG_H

using namespace std;
class PieceBag {
    private:
        vPiece m_Hand;
        PieceFactory* m_PieceFactory;
        SDL_Window* m_Window;
        vector<int> m_SortOfPieces;
        void InitPilePiece();
    public:
        PieceBag();
        PieceBag(PieceFactory* pieceFactory, SDL_Window* window);
        Piece* GetNextPiece();
};


#endif //TP1_PROGAV_PIECEBAG_H
