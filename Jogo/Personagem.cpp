//////////////////////////////////////////////////////////////////////////

#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////
Personagem::Personagem()
{
    sprite = new Sprite("Resources/Personagem.png");
    MoveTo
    (
        float(window->CenterX() - (sprite->Width() /2.0f)), 
        float(window->CenterY() - (sprite->Height() / 2.0f)),
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
        x -= velX * gameTime;

    if (window->KeyDown(VK_RIGHT) and x < (window->Width() - sprite->Width()))
        x += velX * gameTime;

    if (window->KeyDown(VK_UP) and y > 0)
        y -= velY * gameTime;

    if (window->KeyDown(VK_DOWN) and y < (window->Height() - sprite->Height()))
        y += velY * gameTime;

}

//////////////////////////////////////////////////////////////////////////
void Personagem::Draw()
{
    sprite->Draw(x, y, z);
}

//////////////////////////////////////////////////////////////////////////

