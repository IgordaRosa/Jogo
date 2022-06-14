//////////////////////////////////////////////////////////////////////////

#ifndef GAME
#define GAME

//////////////////////////////////////////////////////////////////////////

#include "Window.h"

//////////////////////////////////////////////////////////////////////////
class Game
{
    // Membros protegidos s�o privados para o mundo externo mas
    // p�blicos para as classes derivadas, ou seja, as classes
    // derivadas de Game ser�o capazes de acessar estes membros.
protected:
    static Window* & window;                    // janela do jogo
    static float   & gameTime;                  // tempo do �ltimo quadro

public:
    Game();                                     // construtor
    virtual ~Game();                            // destrutor
    
    // M�todos que podem ser sobrescritos para implementar 
    // funcionalidade espec�fica para o jogo. Eles j� possuem
    // uma implementa��o padr�o.

    virtual void OnPause();                     // pausa do jogo

    // Estes m�todos s�o puramente virtuais, isto �, devem ser 
    // implementados em todas as classes derivas de Game.

    virtual void Init() = 0;                    // inicializa��o do jogo
    virtual void Update() = 0;                  // atualiza��o do jogo
    virtual void Draw() = 0;                    // desenho da cena
    virtual void Finalize() = 0;                // finaliza��o do jogo
};

//////////////////////////////////////////////////////////////////////////

#endif