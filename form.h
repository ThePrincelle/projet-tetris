
#include "block.h"
#include "vec2.h"
#include <vector>

#ifndef _FORM_H
#define _FORM_H

class Form {

    private:
        /**
         * ex:
         * | null, block, null
         * | block, block, block
         */
        Block m_blocks[6];
        bool m_static;

    public:
        Form();
        Form(double x, double y, double vx, double vy);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetVelocity() const;
        bool GetStatus();
        Block *GetBlocks();

        // Setters
        void SetPosition(Vec2 pos);
        void SetVelocity(Vec2 vel);

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Move(double dt);
};


#endif //_FORM_H
