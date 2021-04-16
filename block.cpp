#include "block.h"

// Constructors
Block::Block() : m_Pos(0, 0), m_Vel(0, 0)
{

}
Block::Block(double x, double y, double vx, double vy)
        : m_Pos(x, y), m_Vel(vx, vy)
{

}

// Getters
Vec2 Block::GetPosition() const
{
    return m_Pos;
}
Vec2 Block::GetVelocity() const
{
    return m_Vel;
}

// Setters
void Block::SetPosition(Vec2 &pos) {
    m_Pos = pos;
}
void Block::SetVelocity(Vec2 &vel) {
    m_Vel = vel;
}

// Actions
void Block::AddForce(Vec2 force) {
    m_Vel += force;
}

void Block::MultiplyForce(Vec2 force) {
    m_Vel *= force;
}

void Block::Fall(double dt) {
    Vec2 temp_vec = m_Vel * dt;
    m_Pos += temp_vec;
}

void Block::Move(Vec2& velR) {
    m_Pos += velR;
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

void Block::SelfPaint(WindowSurface* winSurf, Sprite color)
{
    winSurf->Paint(color,m_Pos);
}

void Block::Lock()
{
    Vec2 lock = Vec2(0, 0);
    float x = roundf(m_Pos.x) - fmod(roundf(m_Pos.x),21);
    float y = roundf(m_Pos.y) - fmod(roundf(m_Pos.y),21) + 12;
    MultiplyForce(lock);
    m_Pos = Vec2 (x, y);
}