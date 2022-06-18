//////////////////////////////////////////////////////////////////////////
#ifndef JOGO_JOGO
#define JOGO_JOGO

#include "Engine.h"
#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Resources.h"

#include "Colisores.h"

//objetos
#include "Scene.h"
#include "Personagem.h"
#include "Block.h"
#include "Bola.h"

//////////////////////////////////////////////////////////////////////////
class Jogo : public Game
{
private:
    
    //objetos
    Jogador* personagem = nullptr;

    //sprites
    Sprite* Backg = nullptr;
    Image* Tile1 = nullptr;
    Image* Tile2 = nullptr;
    Image* Tile3 = nullptr;
    Image* Tile4 = nullptr;
    Image* Tile5 = nullptr;

public:
    static Scene* scene;

    void Init();
    void Update();
    void Draw();
    void Finalize();
};

//////////////////////////////////////////////////////////////////////////

#endif
