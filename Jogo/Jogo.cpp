//////////////////////////////////////////////////////////////////////////

#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////

Scene* Jogo::scene = nullptr;

//////////////////////////////////////////////////////////////////////////
void Jogo::Init()
{
    scene = new Scene();

    //carregar imagens
    
    //adicionar objetos a lista
    personagem = new Personagem();
    scene->Add(personagem, RECTANGLE_T);
    
}

//////////////////////////////////////////////////////////////////////////
void Jogo::Update()
{
    //verifica interações de key com o menu
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    //atualiza todos os objetos da lista
    scene->Update();

    //detecção e resolução de colisão
    scene->CollisionDetection();
} 

//////////////////////////////////////////////////////////////////////////
void Jogo::Draw()
{
    //desenha os objetos da lista
    scene->Draw();

}

//////////////////////////////////////////////////////////////////////////
void Jogo::Finalize()
{
    //deleta o menu

    //deleta lista de objetos, e todos os seus objetos
    delete scene;
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
    engine->window->HideCursor(true);
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