//////////////////////////////////////////////////////////////////////////
#ifndef JOGO_JOGO
#define JOGO_JOGO

#include "Engine.h"
#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Resources.h"

//objetos
#include "Scene.h"
#include "Personagem.h"
#include "Block.h"
#include "Bola.h"

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
    
    //lista de objetos
    static Scene* scene;
    Jogador* personagem = nullptr;

    //sprites
    Sprite* Backg = nullptr;
    Image* Tile1 = nullptr;
    Image* Tile2 = nullptr;
    Image* Tile3 = nullptr;
    Image* Tile4 = nullptr;
    Image* Tile5 = nullptr;

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

//////////////////////////////////////////////////////////////////////////

#endif
