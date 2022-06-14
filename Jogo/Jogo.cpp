//////////////////////////////////////////////////////////////////////////

#include "Engine.h"
#include "Game.h"
#include "Image.h"
#include "Sprite.h"
#include "Resources.h"

//objetos
#include "Personagem.h"

//////////////////////////////////////////////////////////////////////////
class SpriteDemo : public Game
{
private:
    Sprite* backg = nullptr;

    Image  * logoImg = nullptr;
    Sprite * logo1   = nullptr;
    Sprite * logo2   = nullptr;

    //objetos
    Personagem* perso = nullptr;

public:
    void Init();
    void Update();
    void Draw();
    void Finalize();
};

//////////////////////////////////////////////////////////////////////////
void SpriteDemo::Init()
{
    backg = new Sprite("Resources/Background.jpg");

    logoImg = new Image("Resources/Logo.png");
    logo1 = new Sprite(logoImg);
    logo2 = new Sprite(logoImg);

    perso = new Personagem();
}

//////////////////////////////////////////////////////////////////////////
void SpriteDemo::Update()
{
    // sai com o pressionar do ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    perso->Update();
} 

//////////////////////////////////////////////////////////////////////////
void SpriteDemo::Draw()
{
    backg->Draw(0.0f, 0.0f, Layer::BACK);
    logo1->Draw(40.0f, 60.0f, Layer::UPPER);
    logo2->Draw(400.0f, 450.0f, Layer::LOWER);

    perso->Draw();
}

//////////////////////////////////////////////////////////////////////////
void SpriteDemo::Finalize()
{
    // remove sprites da mem�ria
    delete backg;
    delete logo1;
    delete logo2;

    // remove imagem da mem�ria
    delete logoImg;

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
    engine->window->Color(0, 0, 0);
    engine->window->Title("Jogo");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);

    // configura dispositivo gr�fico
    engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new SpriteDemo());

    // destr�i o motor e o jogo
    delete engine;
    return status;
}

//////////////////////////////////////////////////////////////////////////