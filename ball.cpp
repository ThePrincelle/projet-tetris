#include "ball.h"

// Constructors
Ball::Ball() : m_Pos(0, 0), m_Vel(0, 0)
{

}
Ball::Ball(double x, double y, double vx, double vy)
        : m_Pos(x, y), m_Vel(vx, vy)
{

}

// Getters
Vec2 Ball::GetPosition() const
{
    return m_Pos;
}
Vec2 Ball::GetVelocity() const
{
    return m_Vel;
}

// Setters
void Ball::SetPosition(Vec2 pos) {
    m_Pos = pos;
}
void Ball::SetVelocity(Vec2 vel) {
    m_Vel = vel;
}

// Actions
void Ball::AddForce(Vec2 force) {
    m_Vel += force;
}
void Ball::MultiplyForce(Vec2 force) {
    m_Vel *= force;
}
void Ball::Move(double dt) {
    Vec2 temp_vec = m_Vel * dt;
    m_Pos += temp_vec;
}