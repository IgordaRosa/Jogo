//////////////////////////////////////////////////////////////////////////

#include "Sprite.h"
#include "Engine.h"

//////////////////////////////////////////////////////////////////////////
// valores de profundidade predefinidos
const float Layer::FRONT  = 0.00f;
const float Layer::UPPER  = 0.25f;
const float Layer::MIDDLE = 0.50f;
const float Layer::LOWER  = 0.75f;
const float Layer::BACK   = 0.99f;

//////////////////////////////////////////////////////////////////////////
Sprite::Sprite(string filename)
{
    // carrega imagem
    image = new Image(filename);
    localImage = true;
    
    // configura registro sprite
    sprite.texture = image->View();
}

//////////////////////////////////////////////////////////////////////////
Sprite::Sprite(const Image * img)
{
    // aponta para imagem externa
    image = img;
    localImage = false;

    // configura registro sprite
    sprite.texture = image->View();
}

//////////////////////////////////////////////////////////////////////////
Sprite::~Sprite()
{
    if (localImage)
        delete image;
}

//////////////////////////////////////////////////////////////////////////
void Sprite::Draw(float x, float y, float z)
{
    sprite.x = x;
    sprite.y = y;
    sprite.scale = 1.0f;
    sprite.depth = z;
    sprite.rotation = 0.0f;
    sprite.width = image->Width();
    sprite.height = image->Height();

    // adiciona o sprite na lista de desenho
    Engine::renderer->Draw(&sprite);
}

//////////////////////////////////////////////////////////////////////////
