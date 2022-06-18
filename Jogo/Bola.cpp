//////////////////////////////////////////////////////////////////////////

#include "Bola.h"
#include "Block.h"
#include "Colisores.h"
#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////
Ball::Ball(Jogador* per)
{
    jogador = per;
    sprite = new Sprite("Resources/Joguinho/Ball.png");
    BBox(new Rect(0, 0, 11, 11));

    MoveTo
    (
        jogador->CentroX,
        float(window->Height() - 87.0f),
        Layer::FRONT
    );

    lancada = false;

    this->type = BALL;

    velX = 200.0f;
    velY = -250.0f;
}

//////////////////////////////////////////////////////////////////////////
Ball::~Ball()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Ball::Update()
{
    if (window->KeyDown(VK_SPACE))
        lancada = true;

    else if (!lancada)
    {
        MoveTo
        (
            jogador->CentroX,
            float(window->Height() - 87.0f),
            Layer::FRONT
        );
        return;
    }

    if (x < 0)
    {
        MoveTo(0.0f,y);
        velX = -velX;
    }

    if (x > window->Width() - (sprite->Width() / 2.0f))
    {
        MoveTo(window->Width() - (sprite->Width() / 2.0f), y);
        velX = -velX;
    }
    
    if (y < 0)
    {
        MoveTo(x, 0.0f);
        velY = -velY;
    }

    if (y > window->Height() - (sprite->Height() / 2.0f))
    {
        lancada = false;
        velX = 200.0f;
        velY = -250.0f;
    }

    Translate(velX * gameTime, velY * gameTime);

}

//////////////////////////////////////////////////////////////////////////
void Ball::OnCollision(Object* obj)
{
    if (obj->Type() == PLAYER)
    {
        velY = -velY;
    }
    if (obj->Type() == BLOCK)
    {
        Jogo::scene->Delete(obj, STATIC);
    }

}

//////////////////////////////////////////////////////////////////////////

