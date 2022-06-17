//////////////////////////////////////////////////////////////////////////

#ifndef JOGO_BOLA
#define JOGO_BOLA

#include "Types.h"
#include "Object.h"
#include "Personagem.h"
#include "Sprite.h"

//////////////////////////////////////////////////////////////////////////
class Ball : public Object
{
private:
    Sprite* sprite;
    Jogador* jogador;

public:

    bool lancada;

    float velX;
    float velY;

    Ball(Jogador* per);
    ~Ball();

    void OnCollision(Object* obj);
    void Update();
    void Draw();
};

//////////////////////////////////////////////////////////////////////////
inline void Ball::Draw()
{
    sprite->Draw(x, y, z);
}

//////////////////////////////////////////////////////////////////////////

#endif
