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
void Block::SetPosition(Vec2 pos) {
    m_Pos = pos;
}
void Block::SetVelocity(Vec2 vel) {
    m_Vel = vel;
}

// Actions
void Block::AddForce(Vec2 force) {
    m_Vel += force;
}

void Block::MultiplyForce(Vec2 force) {
    m_Vel *= force;
}

void Block::Move(double dt) {
    Vec2 temp_vec = m_Vel * dt;
    m_Pos += temp_vec;
}