//////////////////////////////////////////////////////////////////////////

#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////
Personagem::Personagem()
{
    sprite = new Sprite("Resources/Personagem.png");
    MoveTo
    (
        100.0f,//float(window->CenterX() - (sprite->Width() /2.0f)), 
        float(window->CenterY() - (sprite->Height() / 2.0f)) + 200.0f,
        Layer::MIDDLE
    );

    velX = 200.0f;
    velY = 150.0f;
}

//////////////////////////////////////////////////////////////////////////
Personagem::~Personagem()
{
    delete sprite;
}

//////////////////////////////////////////////////////////////////////////
void Personagem::Update()
{
    if (window->KeyDown(VK_LEFT) and x > 0)
        Translate(-velX * gameTime, 0);

    if (window->KeyDown(VK_RIGHT) and x < (window->Width() - sprite->Width()))
        Translate(velX * gameTime, 0);

    if (window->KeyDown(VK_UP) and y > 0)
        Translate(0, -velY * gameTime);

    if (window->KeyDown(VK_DOWN) and y < (window->Height() - sprite->Height()))
        Translate(0, velY * gameTime);


}

//////////////////////////////////////////////////////////////////////////
void Personagem::Draw()
{
    sprite->Draw(x, y, z);
}

//////////////////////////////////////////////////////////////////////////

