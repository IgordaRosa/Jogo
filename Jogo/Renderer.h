//////////////////////////////////////////////////////////////////////////

#ifndef RENDER
#define RENDER

//////////////////////////////////////////////////////////////////////////

#include "Window.h"
#include "Graphics.h"
#include "Sprite.h"
#include <vector>
using std::vector;

//////////////////////////////////////////////////////////////////////////
class Renderer
{
private:
    ID3D11InputLayout        * inputLayout;                 // input layout
    ID3D11VertexShader       * vertexShader;                // vertex shader
    ID3D11PixelShader        * pixelShader;                 // pixel shader
    ID3D11RasterizerState    * rasterState;                 // estado do rasterizador
    ID3D11SamplerState       * sampler;                     // estado do amostrador de textura
    ID3D11Buffer             * vertexBuffer;                // buffer de v�rtices
    ID3D11Buffer             * indexBuffer;                 // buffer de �ndices
    ID3D11Buffer             * constantBuffer;              // buffer para o shader
    uint                       vertexBufferPosition;        // posi��o atual do vertex buffer

    static const uint MinBatchSize = 128;                   // tamanho m�nimo do lote de sprites
    static const uint MaxBatchSize = 4096;                  // tamanho m�ximo do lote de sprites    
    static const uint VerticesPerSprite = 4;                // n�mero de v�rtices por sprite
    static const uint IndicesPerSprite = 6;                 // n�mero de �ndices por sprite

    vector<SpriteData*> spriteVector;                       // vetor de sprites
    
    // renderiza um grupo de sprites de mesma textura
    void RenderBatch(ID3D11ShaderResourceView * texture, SpriteData ** sprites, uint cont);

public:
    Renderer();                                             // construtor
    ~Renderer();                                            // destrutor
    
    bool Initialize(Window * window, Graphics * graphics);  // inicializa o renderizador
    void Draw(SpriteData * sprite);                         // adiciona sprite na lista
    void Render();                                          // envia sprites para desenho    
};

//////////////////////////////////////////////////////////////////////////

#endif