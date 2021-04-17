
#include "board.h"

vector<Board*> Board::m_Boards = vector<Board*>();

Board::Board()
{
    m_Blocks = vBlock(200, nullptr);
    m_RollerCoaster = vint(12,-1);
    m_RollerCoaster[12]= 19;
    m_RollerCoaster[0] = 19;
}

bool Board::SearchIsRowFull(int x)
{
    if(x<0 || x >= m_RollerCoaster.size())
        return false;

    struct Exist
    {
        const int e;
        explicit Exist(int n) : e(n) {}
        bool operator()(int n) const { return n > e; }
    };
    if(!none_of(m_RollerCoaster.cbegin(),m_RollerCoaster.cend(), Exist(x)))
        return false;
}

Board* Board::GetInstanceBoard(int IdGame)
{
    if(IdGame <= 0)
        return nullptr;

    if (m_Boards.size() < IdGame)
        m_Boards.push_back(new Board());


    return m_Boards[IdGame-1];
}

vBlock Board::GetBlocks()
{
    return m_Blocks;
}

void Board::AssignBlocks(vBlock blocks, int w, int h)
{
    for (Block* block : blocks)
        if(block != nullptr)
        {
            Vec2 posInBoard = block->GetPositionInBoard(w, h);

            int x = (int)posInBoard.x;
            int y = (int)posInBoard.y;

            m_RollerCoaster[x] = y>m_RollerCoaster[x]?y:m_RollerCoaster[x];
            x--;
            m_Blocks[y*10 + x] = block;
        }

}

bool Board::IsContact(Vec2 pos)
{
    int x = (int)pos.x -1;
    int y = (int)pos.y;

    if(y == 0)
        return true;

    // Reached the top ! Game Over...
    for (int i = 1; i < m_RollerCoaster.size()-1; ++i) {
        if (m_RollerCoaster[i] >= 19)
            return true;
    }

    int index = (int)(((y-1)*10) + x);
    if(m_Blocks[index] != nullptr)
        return true;
    else
        return false;
}

bool Board::IsContactLeft(Vec2 pos)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    return m_Blocks[y*10 + x -2] != nullptr;
}

bool Board::IsContactRight(Vec2 pos)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    return m_Blocks[y*10 + x] != nullptr;
}

