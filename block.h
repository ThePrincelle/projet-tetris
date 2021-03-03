
#include "vec2.h"

#ifndef _BALL_H_
#define _BALL_H_

class Block {
    // Properties
    private:
        Vec2 m_Pos;
        Vec2 m_Vel;


    public:

        // Constructors
        Block();
        Block(double x, double y, double vx, double vy);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetVelocity() const;

        // Setters
        void SetPosition(Vec2 pos);
        void SetVelocity(Vec2 vel);

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Move(double dt);


};


#endif
