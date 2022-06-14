//////////////////////////////////////////////////////////////////////////

#include "Background_F1.h"

//////////////////////////////////////////////////////////////////////////
Background_F1::Background_F1()
{
    sprite = new Sprite("Resources/Fases/back0.png");
    MoveTo(0.0f, 0.0f, Layer::BACK);
}

//////////////////////////////////////////////////////////////////////////
Background_F1::~Background_F1()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Background_F1::Update()
{
    
}

//////////////////////////////////////////////////////////////////////////
void Background_F1::Draw()
{
    sprite->Draw(x, y, z, 0.7f);
}

//////////////////////////////////////////////////////////////////////////