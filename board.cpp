
#include "board.h"

vector<Board*> Board::m_Boards = vector<Board*>();

Board::Board()
{
    m_Blocks = vBlock(200, nullptr);
    m_RollerCoaster = vint(12,-1);
    m_RollerCoaster[12]= 19;
    m_RollerCoaster[0] = 19;
}

bool Board::SearchIsRowFull(int y)
{
    if(y<0 || y >= 20)
        return false;

    for( int i = 1; i < 11; i++)
        if(m_RollerCoaster[i]<y)
            return false;

    for(int i = 0; i < m_Blocks.size(); i++)
        if(i/10 == y && m_Blocks[i] == nullptr)
            return false;

    return true;
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
    int x = pos.x - 1;
    int y = pos.y;

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

bool Board::DestroyRowIfFull(int y)
{
    if(!SearchIsRowFull(y))
        return false;

    for(int i = 0; i < m_Blocks.size(); i++)
        if(i/10 == y && m_Blocks[i] != nullptr)
        {
            m_Blocks[i]->Erased();
        }
        else if (m_Blocks[i] != nullptr && i/10 >y)
        {
            Vec2 moveDown = Vec2(0,21);
            m_Blocks[i]->Move(moveDown);
        }

    for(int i = 0; i < 10; i++)
    {
        m_Blocks.erase(m_Blocks.begin() + (y * 10));
        m_Blocks.push_back(nullptr);
    }

    for( int i = 1; i < 11; i++)
        m_RollerCoaster[i]--;


    return true;
}


