#ifndef _PIECE_H
#define _PIECE_H
#include <vector>
#include "surface.h"
#include "window_surface.h"
#include <string>
#include <unordered_map>
#include "vec2.h"
#include "form.h"


using namespace std;
typedef vector<Form*> vForm;
enum TetrisPiece { I, J, L, O, S, Z, T, Count};
class Piece  {

    friend class PieceFactory;
    private:
        vForm m_Forms;
        int  m_IdCombination;
        bool m_Static;
        Sprite m_Color;
        Piece();
        Piece(vForm &forms, Sprite color);

    public:
        // Getters
        vForm GetCombinations() const;
        Vec2 GetPosition();
        Vec2 GetVelocity();
        Vec2 GetMaxDownPosition();
        Vec2 GetMaxUpPosition();
        Vec2 GetMaxRightPosition();
        Vec2 GetMaxLeftPosition();
        vBlock GetBlocks();
        Form* GetCurrentForm();
        bool IsStatic();

        // Setters
        void SetPosition(Vec2 &pos);
        void SetVelocity(Vec2 &vel);
        void AddCombination(Form* form);

        // Actions
        void AddForce(Vec2 force);
        void MultiplyForce(Vec2 force);
        void Fall(double dt, Board* board, int w, int h);
        void MoveRight(Board* board);
        void MoveLeft(Board* board);
        void Move(Vec2 pos, bool forceMove);
        void RotateRight();
        void RotateLeft();
        void Sprint();
        void StopSprint();
        void SelfPaint(WindowSurface* winSurf);
        void SetStatic(bool isStatic);
        void Lock();


};

typedef vector<Piece*> vPiece;
class PieceFactory
{
    public:
            static PieceFactory* m_PieceFactory;
            static PieceFactory* GetPieceFactory()
            {
                if(m_PieceFactory == nullptr)
                    m_PieceFactory = new PieceFactory();
                return m_PieceFactory;
            }

    private:
        vPiece m_AllPiece;
        Vec2 m_StartPos;
        Vec2 m_StartVel;
        unordered_map<string, Sprite> m_Sprites;
        PieceFactory() : m_Sprites(){}

    public:
        PieceFactory(PieceFactory const&)    = delete;
        void operator=(PieceFactory const&)  = delete;

        Piece* CreatePiece(TetrisPiece typePiece, double x, double y);
        Piece* CreatePiece(TetrisPiece typePiece, double x, double y, double vx, double vy);
        Vec2 GetStartPos() const;
        Vec2 GetStartVel() const;
        vPiece GetAllPiece();

        void SetStartPos(Vec2 &pos);
        void SetStartVel(Vec2 &vel);
        unordered_map<string, Sprite> GetSprites();
        void SetSprites(unordered_map<string, Sprite> &sprites);
        void ReloadPosition(Piece *piece);
        void ReloadVelocity(Piece *piece, float force);
        void DrawAllPiece(WindowSurface *winSurf);

};

#endif //_PIECE_H
