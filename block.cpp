#include "block.h"

// Constructors
Block::Block() : m_Pos(0, 0), m_Vel(0, 0), m_Erased(false)
{

}
Block::Block(double x, double y, double vx, double vy)
        : m_Pos(x, y), m_Vel(vx, vy), m_Erased(false)
{

}

// Getters
Vec2 Block::GetPosition() const
{
    return m_Pos;
}

// Get the position in a board
Vec2 Block::GetPositionInBoard(int w,int h)
{
    float x,y;

    if((w/2.0 - 21.0 * 5.0) > m_Pos.x)
       x = 0;
    else if((w/2.0 + 21.0 * 5.0) < m_Pos.x)
       x = 9;
    else if(w/2.0 > m_Pos.x)
        x = floor((m_Pos.x-(w/2.0 - 21.0 * 5.0))/21);
    else
        x = floor((m_Pos.x-(w/2.0 - 21.0 * 5.0))/21);

    if((h - 2*21) < m_Pos.y)
        y = 0;
    else if((h - 23*21) > m_Pos.y)
        y = 19;
    else
        y = 20 - floor(((m_Pos.y-(h - 23*21))/21));

    return Vec2(x,y);
}

Vec2 Block::GetVelocity() const
{
    return m_Vel;
}

// Check if value is in board.
bool Block::IsInBoard(int w,int h)
{
    if((w/2.0 - 21.0 * 5.0) < m_Pos.x && (w/2.0 + 21.0 * 6.0) > m_Pos.x)
        if((h - 2*21) > m_Pos.y &&  (h - 22*21) < m_Pos.y)
            return true;

    return false;
}

// Setters
void Block::SetPosition(Vec2 &pos) {
    m_Pos = pos;
}

void Block::SetVelocity(Vec2 &vel) {
    m_Vel = vel;
}

void Block::Erased() {
    m_Erased = true;
}

// Actions
void Block::AddForce(Vec2 force) {
    m_Vel += force;
}

void Block::MultiplyForce(Vec2 force) {
    m_Vel *= force;
}

// Fall function to set the block to fall
void Block::Fall(double dt) {

    Vec2 temp_vec = m_Vel * dt;
    m_Pos += temp_vec;
}

void Block::Move(Vec2& vel) {
    m_Pos += vel;
}

void Block::Sprint()
{
    Vec2 sprint = Vec2(1, 20);
    MultiplyForce(sprint);
}

void Block::StopSprint()
{
    Vec2 stopSprint = Vec2(1, 0.05);
    MultiplyForce(stopSprint);
}

// Displays the Block
void Block::SelfPaint(WindowSurface* winSurf, Sprite color)
{
    if(!m_Erased)
        winSurf->Paint(color,m_Pos);
}

// Locks the block in place
void Block::Lock()
{
    Vec2 lock = Vec2(0, 0);
    float x = roundf(m_Pos.x) - fmod(roundf(m_Pos.x),21);
    float y = roundf(m_Pos.y) - fmod(roundf(m_Pos.y),21) + 12;
    MultiplyForce(lock);
    m_Pos = Vec2 (x, y);
}