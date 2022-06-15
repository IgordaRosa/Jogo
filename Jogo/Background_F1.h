//////////////////////////////////////////////////////////////////////////
#ifndef BACKGROUND
#define BACKGROUND

#include "Types.h"
#include "Object.h"
#include "Sprite.h"
#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////
class Background_F1 : public Object
{
private:
    Sprite* sprite;
    Personagem* personagem;
    float velX;

public:
    Background_F1(Personagem * perso);
    ~Background_F1();

    void Update();
    void Draw();
};

//////////////////////////////////////////////////////////////////////////

#endif
