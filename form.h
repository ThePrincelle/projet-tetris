
#include "block.h"
#include "vec2.h"
#include "sprite.h"
#include "window_surface.h"
#include <cmath>
#include <vector>

#ifndef _FORM_H
#define _FORM_H

using namespace std;
typedef std::vector<Block*> vBlock;
class Form {

    private:
        /**
         * ex:
         * | null, block, null, null
         * | block, block, block ,null
         * | null, null, null, null
         * | null, null, null, null
         */
        vBlock m_Blocks;
        Vec2 m_Pos;
        Vec2 m_Vel;

    public:
        Form();
        Form(double x, double y, double vx, double vy, vBlock &blocks);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetMaxDownPosition();
        Vec2 GetMaxUpPosition();
        Vec2 GetVelocity() const;
        vBlock GetBlocks() const;

        // Setters
        void SetPosition(Vec2 &pos);
        void SetVelocity(Vec2 &vel);

        // Actions
        void AddForce(Vec2 &force);
        void MultiplyForce(Vec2 &force);
        void Fall(double dt);
        void MoveRight(Vec2 & velR);
        void MoveLeft(Vec2 & velL);
        void Sprint();
        void StopSprint();
        void SelfPaint(WindowSurface* winSurf, Sprite color);
        void Lock();

};


#endif //_FORM_H
