//////////////////////////////////////////////////////////////////////////
#ifndef JOGO
#define JOGO

#include "Engine.h"
#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Resources.h"

//menu
#include "Menu.h"

//objetos
#include "Scene.h"
#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////

enum ObjTypes
{
    PLAYER,                             // jogador
    BALL,                               // bola
    BLOCK                               // bloco
};

//////////////////////////////////////////////////////////////////////////
class Jogo : public Game
{
private:
    //menu
    
    //lista de objetos
    static Scene* scene;
    Personagem* personagem = nullptr;

    //sprites

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

//////////////////////////////////////////////////////////////////////////

#endif
