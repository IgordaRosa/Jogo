//////////////////////////////////////////////////////////////////////////

#include "Engine.h"
#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Resources.h"

//menu
#include "Menu.h"

//objetos
#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////
class Jogo : public Game
{
private:
    Sprite* back0 = nullptr;

    //menu
    Menu* menu = nullptr;
    //objetos
    Personagem* perso = nullptr;

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

//////////////////////////////////////////////////////////////////////////
void Jogo::Init()
{
    back0 = new Sprite("Resources/Fases/back0.png");

    menu = new Menu();

    perso = new Personagem();
}

//////////////////////////////////////////////////////////////////////////
void Jogo::Update()
{
    menu->KeyInteract();

    perso->Update();
} 

//////////////////////////////////////////////////////////////////////////
void Jogo::Draw()
{
    back0->Draw(0.0f, 0.0f, Layer::BACK, 0.7f);

    perso->Draw();
}

//////////////////////////////////////////////////////////////////////////
void Jogo::Finalize()
{
    // remove sprites da mem�ria
    delete back0;

    //deleta objeto
    delete perso;
}

//////////////////////////////////////////////////////////////////////////
int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, 
                     _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    // cria motor de jogo
    Engine * engine = new Engine();
    
    // configura janela
    engine->window->Mode(WINDOWED);
    engine->window->Size(1280, 720);
    // fullscreen
    //engine->window->Mode(FULLSCREEN);
    //engine->window->HideCursor(true);
    //////////////////////////////////
    engine->window->Color(0, 0, 0);
    engine->window->Title("Jogo");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gr�fico
    engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new Jogo());

    // destr�i o motor e o jogo
    delete engine;
    return status;
}

//////////////////////////////////////////////////////////////////////////