//////////////////////////////////////////////////////////////////////////

#ifndef ENGINE
#define ENGINE

//////////////////////////////////////////////////////////////////////////

#include "Game.h"                        // implementa��o do jogo
#include "Window.h"                      // janela do jogo
#include "Graphics.h"                    // hardware gr�fico
#include "Renderer.h"                    // renderizador de sprites
#include "Timer.h"                       // medidor de tempo

//////////////////////////////////////////////////////////////////////////
class Engine
{
private:
    static Timer timer;                  // medidor de tempo
    static bool paused;                  // estado do jogo

    float FrameTime();                   // calcula o tempo do quadro
    int   Loop();                        // inicia execu��o do jogo

public:
    static Game     * game;              // jogo a ser executado
    static Window   * window;            // janela do jogo
    static Graphics * graphics;          // dispositivo gr�fico
    static Renderer * renderer;          // renderizador de sprites
    static float      frameTime;         // tempo do quadro atual

    Engine();                            // construtor
    ~Engine();                           // destrutor

    int Start(Game* level);              // inicia a execu��o do jogo
    
    static void Pause();                 // pausa o jogo
    static void Resume();                // reinicia o jogo
};

//////////////////////////////////////////////////////////////////////////

#endif