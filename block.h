
#include "vec2.h"
#include "window_surface.h"
#include "surface.h"
#include "sprite.h"


#ifndef _BLOCK_H_
#define _BLOCK_H_

class Block {
    // Properties
    private:
        Vec2 m_Pos;
        Vec2 m_Vel;
        bool m_Erased;

    public:
        // Constructors
        Block();
        Block(double x, double y, double vx, double vy);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetVelocity() const;
        Vec2 GetPositionInBoard(int w,int h);
        bool IsInBoard(int w,int h);

        // Setters
        void SetPosition(Vec2 &pos);
        void SetVelocity(Vec2 &vel);
        void Erased();

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Fall(double dt);
        void Move(Vec2& vel);
        void Sprint();
        void StopSprint();
        void SelfPaint(WindowSurface* winSurf, Sprite color);
        void Lock();
};


#endif
