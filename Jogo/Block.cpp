//////////////////////////////////////////////////////////////////////////

#include "Block.h"
#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////
Block::Block(Image * s,float Xinit, float Yinit)
{
    sprite = new Sprite(s);
    BBox(new Rect(0, 0, float(sprite->Width()*2.0f) -1.0f, float(sprite->Height()*2.0f) -1.0f));

    MoveTo
    (
        float(window->CenterX() - sprite->Width()) + Xinit,
        Yinit,
        Layer::MIDDLE
    );

    this->type = BLOCK;
}

//////////////////////////////////////////////////////////////////////////
Block::~Block()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Block::Update()
{
    

}

//////////////////////////////////////////////////////////////////////////
void Block::OnCollision(Object* obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        /*Ball* ball = (Ball*)obj;
        ball->velY = -ball->velY;*/
    }
}

//////////////////////////////////////////////////////////////////////////
