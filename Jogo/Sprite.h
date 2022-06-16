//////////////////////////////////////////////////////////////////////////

#ifndef SPRITEIMG
#define SPRITEIMG

//////////////////////////////////////////////////////////////////////////

#include "Image.h"

//////////////////////////////////////////////////////////////////////////
struct SpriteData
{
    float x, y;
    float scale;
    float depth;
    float rotation;
    uint  width;
    uint  height;
    ID3D11ShaderResourceView* texture;
};

//////////////////////////////////////////////////////////////////////////
struct Layer
{
    static const float FRONT;
    static const float UPPER;
    static const float MIDDLE;
    static const float LOWER;
    static const float BACK;
};

//////////////////////////////////////////////////////////////////////////
class Sprite
{
private:
    SpriteData sprite;              // dados do sprite 
    bool localImage;                // imagem local ou externa
    const Image * image;            // ponteiro para uma imagem

public:
    Sprite(string filename);        // constroi sprite a partir de um arquivo
    Sprite(const Image * img);      // constroi sprite a partir de imagem existente
    ~Sprite();                      // destrutor do sprite

    int Width();                    // largura do sprite
    int Height();                   // altura do sprite

    // desenha imagem na posi��o (x,y) e profundidade (z)
    void Draw(float x, float y, float z = Layer::MIDDLE, float scale = 1.0f);
};

//////////////////////////////////////////////////////////////////////////
// retorna a largura do sprite
inline int Sprite::Width() 
{ return image->Width(); }

// retorna a altura do sprite
inline int Sprite::Height() 
{ return image->Height(); }

//////////////////////////////////////////////////////////////////////////

#endif