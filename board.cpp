
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
        bool operator()(int n) const { return n < e; }
    };
    return none_of(m_RollerCoaster.cbegin(),m_RollerCoaster.cend(), Exist(x));
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
            m_Blocks[x * y] = block;
        }

}

bool Board::IsContact(Vec2 pos, Block* block)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    if(m_RollerCoaster[x] + 1 >= y)
        return true;
    else
        return false;
}

bool Board::IsContactLeft(Vec2 pos, Block* block)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    if(m_RollerCoaster[x] >= y)
        return true;
    else
        return false;
}

bool Board::IsContactRight(Vec2 pos, Block* block)
{
    int x = (int)pos.x;
    int y = (int)pos.y;

    if(m_RollerCoaster[x+1] >= y)
        return true;
    else
        return false;
}

