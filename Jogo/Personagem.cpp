//////////////////////////////////////////////////////////////////////////

#include "Personagem.h"
#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////
Jogador::Jogador()
{
    sprite = new Sprite("Resources/Joguinho/Player.png");
    BBox(new Rect(0, 0, float(sprite->Width())-1.0f, float(sprite->Height()) - 1.0f));

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

    MoveTo
    (
        float(window->CenterX() - (sprite->Width()/2.0f)), 
        float(window->Height() - 75.0f),
        Layer::MIDDLE
    );

    velX = 300.0f;
    velY = 150.0f;

    CentroX = x + (sprite->Width() / 2.0f);

    this->type = PLAYER;
}

//////////////////////////////////////////////////////////////////////////
Jogador::~Jogador()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Jogador::Update()
{
    if (window->KeyDown(VK_LEFT) and x > 5)
        Translate(-velX * gameTime, 0);

    if (window->KeyDown(VK_RIGHT) and x < (window->Width() - sprite->Width()))
        Translate(velX * gameTime, 0);

    CentroX = x + (sprite->Width() / 2.0f);
}

//////////////////////////////////////////////////////////////////////////
void Jogador::OnCollision(Object* obj)
{
}

//////////////////////////////////////////////////////////////////////////

