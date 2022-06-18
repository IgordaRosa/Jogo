//////////////////////////////////////////////////////////////////////////

#include "Jogo.h"

//////////////////////////////////////////////////////////////////////////

Scene* Jogo::scene = nullptr;

//////////////////////////////////////////////////////////////////////////
void Jogo::Init()
{
    scene = new Scene();

    //carregar imagens
    Backg = new Sprite("Resources/Joguinho/background.jpg");

    Tile1 = new Image("Resources/Joguinho/Tile1.png");
    Tile2 = new Image("Resources/Joguinho/Tile2.png");
    Tile3 = new Image("Resources/Joguinho/Tile3.png");
    Tile4 = new Image("Resources/Joguinho/Tile4.png");
    Tile5 = new Image("Resources/Joguinho/Tile5.png");

    //adicionar objetos a lista
    personagem = new Jogador();
    scene->Add(personagem, MOVING);
    scene->Add(new Ball(personagem), MOVING);

    scene->Add(new Block(Tile1,-300, 25), STATIC);
    scene->Add(new Block(Tile2, -150, 25), STATIC);
    scene->Add(new Block(Tile3, 0, 25), STATIC);
    scene->Add(new Block(Tile4, 150, 25), STATIC);
    scene->Add(new Block(Tile5, 300, 25), STATIC);

    scene->Add(new Block(Tile1, -300, 100), STATIC);
    scene->Add(new Block(Tile2, -150, 100), STATIC);
    scene->Add(new Block(Tile3, 0, 100), STATIC);
    scene->Add(new Block(Tile4, 150, 100), STATIC);
    scene->Add(new Block(Tile5, 300, 100), STATIC);

    scene->Add(new Block(Tile1, -300, 175), STATIC);
    scene->Add(new Block(Tile2, -150, 175), STATIC);
    scene->Add(new Block(Tile3, 0, 175), STATIC);
    scene->Add(new Block(Tile4, 150, 175), STATIC);
    scene->Add(new Block(Tile5, 300, 175), STATIC);

    scene->Add(new Block(Tile1, -300, 250), STATIC);
    scene->Add(new Block(Tile2, -150, 250), STATIC);
    scene->Add(new Block(Tile3, 0, 250), STATIC);
    scene->Add(new Block(Tile4, 150, 250), STATIC);
    scene->Add(new Block(Tile5, 300, 250), STATIC);
    
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
    //desenha o backgroud
    Backg->Draw(0.0f, 0.0f, Layer::BACK);

    //desenha os objetos da lista
    scene->Draw();

}

//////////////////////////////////////////////////////////////////////////
void Jogo::Finalize()
{
    //deleta imagens
    delete Backg;
    delete Tile1;
    delete Tile2;
    delete Tile3;
    delete Tile4;
    delete Tile5;

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