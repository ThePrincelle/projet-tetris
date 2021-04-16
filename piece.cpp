
#include "piece.h"

// Constructors
Piece::Piece() : m_IdCombination(0), m_Static(true)
{

}

Piece::Piece(vForm &forms, Sprite color)
        : m_Forms(forms), m_IdCombination(0), m_Static(false), m_Color(color)
{
}

// Getters
Form *Piece::GetCurrentForm()
{
    return m_Forms[m_IdCombination];
}

vBlock Piece::GetBlocks()
{
    return GetCurrentForm()->GetBlocks();
}

vForm Piece::GetCombinations() const
{
    return m_Forms;
}

bool Piece::IsStatic()
{
    return m_Static;
}

Vec2 Piece::GetPosition()
{
    return GetCurrentForm()->GetPosition();
}

Vec2 Piece::GetMaxDownPosition()
{
    return GetCurrentForm()->GetMaxDownPosition();
}

Vec2 Piece::GetMaxUpPosition()
{
    return GetCurrentForm()->GetMaxUpPosition();
}

Vec2 Piece::GetMaxRightPosition()
{
    return GetCurrentForm()->GetMaxRightPosition();
}

Vec2 Piece::GetMaxLeftPosition()
{
    return GetCurrentForm()->GetMaxLeftPosition();
}

Vec2 Piece::GetVelocity()
{
    return GetCurrentForm()->GetVelocity();
}

// Setters
void Piece::SetPosition(Vec2 &pos) {
    for(Form* temp_form : m_Forms)
        temp_form->SetPosition(pos);
}

void Piece::SetVelocity(Vec2 &vel) {
    for(Form* temp_form : m_Forms)
        temp_form->SetVelocity(vel);

    if(vel.x != 0 || vel.y != 0)
        m_Static = false;
}

void Piece::AddCombination(Form *form)
{
    m_Forms.push_back(form);
}

// Actions
void Piece::AddForce(Vec2 force) {
    for(Form* temp_form : m_Forms)
        temp_form->AddForce(force);

    if(force.x != 0 || force.y != 0)
        m_Static = false;
}

void Piece::MultiplyForce(Vec2 force) {
    for(Form* temp_form : m_Forms)
        temp_form->MultiplyForce(force);
}

void Piece::Fall(double dt, int windowHeight) {
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->Fall(dt);
    // Collision bords
    if (GetMaxDownPosition().y > (float)( windowHeight - 3*21))
        if(!m_Static)
            Lock();

    if(GetMaxUpPosition().y < 1) {
        if(!m_Static){

        }
        //End game
    }
}

void  Piece::MoveRight()
{
    Vec2 temp_vec = Vec2(21,0);
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->Move(temp_vec);
}

void  Piece::Move( Vec2 pos)
{
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->Move(pos);
}

void  Piece::MoveLeft()
{
    Vec2 temp_vec = Vec2(-21,0);
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->Move(temp_vec);
}

void Piece::RotateRight()
{
    if(!m_Static) {
        if ((m_IdCombination + 1) >= m_Forms.size())
            m_IdCombination = 0;
        else
            m_IdCombination++;
    }
}

void Piece::RotateLeft()
{
    if(!m_Static) {
        if ((m_IdCombination - 1) < 0)
            m_IdCombination = (int) m_Forms.size() - 1;
        else
            m_IdCombination--;
    }
}

void Piece::Sprint()
{
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->Sprint();
}

void Piece::StopSprint()
{
    if(!m_Static)
        for(Form* temp_form : m_Forms)
            temp_form->StopSprint();
}

void Piece::SelfPaint(WindowSurface* winSurf)
{
    Form* currentForm =  GetCurrentForm();
    currentForm->SelfPaint(winSurf, m_Color);
}

void Piece::SetStatic(bool isStatic)
{
    m_Static= isStatic;
}

void Piece::Lock()
{
    m_Static = true;
    for(Form* temp_form : m_Forms)
        temp_form->Lock();
}

PieceFactory* PieceFactory::m_PieceFactory = nullptr;

Piece* PieceFactory::CreatePiece(TetrisPiece typePiece, double x, double y, double vx, double vy)
{
        vForm forms = vForm();
        string color;
        if(typePiece ==  TetrisPiece::I ) {

            vBlock formI1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), (new Block()),
            };
            forms.push_back(new  Form(x, y, vx, vy, formI1Blocks));

            vBlock formI2Blocks = {
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formI2Blocks));

            color = "LBlue";
        }
        else if (typePiece == TetrisPiece::J ) {

            vBlock formJ1Blocks = {
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formJ1Blocks));

            vBlock formJ2Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formJ2Blocks));

            vBlock formJ3Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
                    nullptr, nullptr,             (new Block()), nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formJ3Blocks));

            vBlock formJ4Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formJ4Blocks));

            color = "DBlue";
        }
        else if (typePiece == TetrisPiece::L) {

            vBlock formL1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr,             (new Block()), nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formL1Blocks));

            vBlock formL2Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formL2Blocks));

            vBlock formL3Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formL3Blocks));

            vBlock formL4Blocks = {
                    (new Block()), (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
            };
            forms.push_back(new Form(x, y, vx, vy, formL4Blocks));

            color = "Orange";
        }
        else if (typePiece == TetrisPiece::O) {

            vBlock formL1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
            };
            forms.push_back(new Form(x, y, vx, vy, formL1Blocks));

            color = "Yellow";
        }
        else if (typePiece == TetrisPiece::S)
        {
            vBlock formS1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr,       (new Block()), (new Block()), nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formS1Blocks));

            vBlock formS2Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formS2Blocks));

            color = "Green";
        }
        else if (typePiece == TetrisPiece::Z) {
            vBlock formZ1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    nullptr, (new Block()), (new Block()), nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formZ1Blocks));

            vBlock formZ2Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formZ2Blocks));

            color = "Red";
        }
        else if (typePiece == TetrisPiece::T) {
            vBlock formT1Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, (new Block()), nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formT1Blocks));

            vBlock formT2Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    (new Block()), nullptr, nullptr, nullptr,
            };
            forms.push_back(new Form(x, y, vx, vy, formT2Blocks));

            vBlock formT3Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr, nullptr, nullptr, nullptr,
                    (new Block()), (new Block()), (new Block()), nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
            };
            forms.push_back(new  Form(x, y, vx, vy, formT3Blocks));

            vBlock formT4Blocks = {
                    nullptr, nullptr, nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
                    (new Block()), (new Block()), nullptr, nullptr,
                    nullptr,       (new Block()), nullptr, nullptr,
            };
            forms.push_back(new Form(x, y, vx, vy, formT4Blocks));

            color = "Magenta";
        }

    auto new_Piece = new Piece(forms,m_Sprites["Block"+color]);
    m_AllPiece.push_back(new_Piece);
    return new_Piece;
}

Piece* PieceFactory::CreatePiece(TetrisPiece typePiece, double x, double y)
{
    Piece *  new_piece = CreatePiece(typePiece, x, y, m_StartVel.x, m_StartVel.y);
    new_piece->SetStatic(true);

    return new_piece;
}

Vec2 PieceFactory::GetStartPos() const {
    return m_StartPos;
}

Vec2 PieceFactory::GetStartVel() const {
    return m_StartVel;
}

vPiece PieceFactory::GetAllPiece() {
    return m_AllPiece;
}

void PieceFactory::SetStartPos(Vec2 &pos) {
   m_StartPos = pos;
}

void PieceFactory::SetStartVel(Vec2 &vel) {
    m_StartVel = vel;
}

unordered_map<string, Sprite> PieceFactory::GetSprites()
{
    return m_Sprites;
}

void PieceFactory::SetSprites(unordered_map<string, Sprite> &sprites)
{
    m_Sprites = sprites;
}

void PieceFactory::ReloadPosition(Piece *piece)
{
    piece->SetPosition(m_StartPos);
}

void PieceFactory::ReloadVelocity(Piece *piece, float force)
{
    Vec2 new_Vel = Vec2(m_StartVel.x,m_StartVel.y*force);
    piece->SetVelocity(new_Vel);
}

void PieceFactory::DrawAllPiece(WindowSurface *winSurf)
{
    for(Piece* temp_piece : m_AllPiece)
        temp_piece->SelfPaint(winSurf);
}