
#ifndef _PIECE_H
#define _PIECE_H
#include "vec2.h"
#include <vector>

class piece {

    private:
        Form m_current_combination;
        vector<Form> m_Forms;
        int  m_id_Combination;
        bool m_static;
        Vec2 m_Vel;

    public:
        Form();
        Form(double x, double y, double vx, double vy);

        // Getters
        Vec2 GetPosition() const;
        Vec2 GetVelocity() const;
        Block *GetBlocks();
        vector<Form> GetCombinations();
        Form GetCurrentForm();
        bool GetStatus();

        // Setters
        void SetPosition(Vec2 pos);
        void SetVelocity(Vec2 vel);
        void AddCombination();

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Move(double dt);
        void RotateRight();
        void RotateLeft();
        void SpeedDown();
};


#endif //_PIECE_H
