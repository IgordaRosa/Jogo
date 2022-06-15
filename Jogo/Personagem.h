//////////////////////////////////////////////////////////////////////////

#ifndef PERSONAGEM
#define PERSONAGEM

#include "Types.h"
#include "Object.h"
#include "Sprite.h"

//////////////////////////////////////////////////////////////////////////
class Personagem : public Object
{
private:
    Sprite* sprite;

public:
    float velX;
    float velY;

    Personagem();
    ~Personagem();

    void Update();
    void Draw();
};

//////////////////////////////////////////////////////////////////////////

#endif
