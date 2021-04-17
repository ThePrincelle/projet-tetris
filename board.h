#include "block.h"
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <iostream>
#include <functional>

#ifndef TP1_PROGAV_BOARD_H
#define TP1_PROGAV_BOARD_H


using namespace std;
typedef std::vector<Block*> vBlock;
typedef std::vector<int> vint;
class Board {

    private:
        static vector<Board*> m_Boards;

    public:
        static Board* GetInstanceBoard(int IdGame);

    private:
        vBlock m_Blocks;
        vint m_RollerCoaster;
        Board();
        bool SearchIsRowFull(int x);

    public:
        vBlock GetBlocks();
        void AssignBlocks(vBlock blocks, int w, int h);
        bool IsContact(Vec2 pos, Block* block);
        bool IsContactLeft(Vec2 pos, Block* block);
        bool IsContactRight(Vec2 pos, Block* block);

};


#endif //TP1_PROGAV_BOARD_H
