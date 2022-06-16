//////////////////////////////////////////////////////////////////////////

#include "Personagem.h"
#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////
Personagem::Personagem()
{
    BBox(new Rect(0, 0, 199, 39));

    // bounding box alternativa: experimente usar 
    // uma combinação de retângulos e círculos

    //Mixed * mixed = new Mixed();
    //
    //Circle * cLeft = new Circle(10.0f);
    //cLeft->MoveTo(0.0f, 0.0f);

    //Circle * cRight = new Circle(10.0f);
    //cRight->MoveTo(80.0f, 0.0f);

    //Rect * rect = new Rect(0.0f, 0.0f, 80.0f, 20.0f);
    //rect->MoveTo(10, 0);
    //
    //mixed->Insert(cLeft);
    //mixed->Insert(cRight);
    //mixed->Insert(rect);
    //
    //bbox = mixed;

    sprite = new Sprite("Resources/Joguinho/Player.png");
    MoveTo
    (
        float(window->CenterX() - (sprite->Width()/2.0f)), 
        float(window->Height() - 75.0f),
        Layer::MIDDLE
    );

    velX = 300.0f;
    velY = 150.0f;

    state = STOPED;

    this->type = PLAYER;
}

//////////////////////////////////////////////////////////////////////////
Personagem::~Personagem()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Personagem::Update()
{
    if (window->KeyDown(VK_LEFT) and x > 5)
        Translate(-velX * gameTime, 0);

    if (window->KeyDown(VK_RIGHT) and x < (window->Width() - sprite->Width()))
        Translate(velX * gameTime, 0);

}

//////////////////////////////////////////////////////////////////////////
void Personagem::OnCollision(Object* obj)
{
    // bola colidiu com o player
    if (obj->Type() == BALL)
    {
        /*Ball* ball = (Ball*)obj;
        ball->velY = -ball->velY;*/
    }
}

//////////////////////////////////////////////////////////////////////////

