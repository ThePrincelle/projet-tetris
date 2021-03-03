
#include "block.h"
#include "vec2.h"

#ifndef _FORM_H
#define _FORM_H

class Form {

    private:
        /**
         * ex:
         * | null, block, null
         * | block, block, block
         */
        Block m_blocks[16];

    public:
        Form();
        Form(double x, double y, double vx, double vy);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetVelocity() const;
        Block *GetBlocks();
        int GetLastLine();

        // Setters
        void SetPosition(Vec2 pos);
        void SetVelocity(Vec2 vel);

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Move(double dt);

};


#endif //_FORM_H
