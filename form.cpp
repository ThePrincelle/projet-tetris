
#include "form.h"

// Constructors
Form::Form() : m_Pos(0, 0), m_Vel(0, 0)
{

}

Form::Form(double x, double y, double vx, double vy, vBlock &blocks)
        : m_Pos(x, y), m_Vel(vx, vy)
{
    m_Blocks = blocks;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
        {
            float new_x = x+((i%4)*21);
            float new_y = y+((floor(i/4)*21));
            Vec2 new_Pos = Vec2(new_x,new_y);
            Vec2 new_Vel = Vec2(vx, vy);
            m_Blocks[i]->SetPosition(new_Pos);
            m_Blocks[i]->SetVelocity(new_Vel);
        }
}

// Getters
vBlock Form::GetBlocks() const
{
    return m_Blocks;
}

Vec2 Form::GetPosition() const
{
    return m_Pos;
}

Vec2 Form::GetMaxDownPosition()
{
    for(int i = 12; i<16; i++)
        if(m_Blocks[i] != nullptr)
            return m_Blocks[i]->GetPosition();
    return Vec2(0,0); //Erreur
}

Vec2 Form::GetMaxUpPosition()
{
    return Vec2(0,0);
}

Vec2 Form::GetMaxRightPosition()
{
    int modulo = 3;
    do {
        for (int i = 3; i < 16; i++)
            if (i % 4 == modulo)
                if (m_Blocks[i] != nullptr)
                    return m_Blocks[i]->GetPosition();
        modulo--;
    }while(modulo != 0);
    return Vec2(0,0); //Erreur
}

Vec2 Form::GetMaxLeftPosition()
{
    for(int i = 0; i<16; i++)
        if(i%4 == 0)
            if(m_Blocks[i] != nullptr)
                return m_Blocks[i]->GetPosition();
    return Vec2(0,0); //Erreur
}

Vec2 Form::GetVelocity() const
{
    return m_Vel;
}

// Setters
void Form::SetPosition(Vec2 &pos) {
    m_Pos = pos;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
        {
            float x = pos.x;
            float y = pos.y;
            float new_x = x+((i%4)*21);
            float new_y = y+((floor(i/4)*21));
            Vec2 new_Pos = Vec2(new_x,new_y);
            m_Blocks[i]->SetPosition(new_Pos);
        }
}

void Form::SetVelocity(Vec2 &vel) {
    m_Vel = vel;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->SetVelocity(vel);
}

// Actions
void Form::AddForce(Vec2 &force) {
    m_Vel += force;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->AddForce(force);
}

void Form::MultiplyForce(Vec2 &force) {
    m_Vel *= force;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->MultiplyForce(force);
}

void Form::Fall(double dt) {
    Vec2 temp_vec = Vec2(0,m_Vel.y * dt);
    m_Pos += temp_vec;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->Fall(dt);
}

void Form::MoveRight(Vec2 & velR)
{
    m_Pos += velR;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->MoveRight(velR);
}

void Form::MoveLeft(Vec2 & velL)
{
    m_Pos += velL;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->MoveLeft(velL);
}

void Form::Sprint()
{
    Vec2 sprint = Vec2(0, 20);
    m_Vel *= sprint;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->Sprint();
}

void Form::StopSprint()
{
    Vec2 stopSprint = Vec2(0, 0.05);
    m_Vel *= stopSprint;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->StopSprint();
}

void Form::SelfPaint(WindowSurface* winSurf, Sprite color)
{
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->SelfPaint(winSurf, color);
}

void Form::Lock()
{
    Vec2 lock = Vec2(0, 0);
    m_Vel *= lock;
    for(int i = 0; i<16; i++)
        if(m_Blocks[i] != nullptr)
            m_Blocks[i]->Lock();
}