//////////////////////////////////////////////////////////////////////////
#include "Game.h"
#include "Engine.h"

//////////////////////////////////////////////////////////////////////////

Window* & Game::window   = Engine::window;       // ponteiro para a janela
float   & Game::gameTime = Engine::frameTime;    // tempo do �ltimo quadro

//////////////////////////////////////////////////////////////////////////
Game::Game()
{
}

//////////////////////////////////////////////////////////////////////////
Game::~Game()
{
}

//////////////////////////////////////////////////////////////////////////
void Game::OnPause()
{
    Sleep(10);
}

//////////////////////////////////////////////////////////////////////////