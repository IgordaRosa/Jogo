//////////////////////////////////////////////////////////////////////////

// matriz de transforma��o e proje��o
cbuffer ConstantBuffer
{
    float4x4 WorldViewProj;
}

// estrutura dos v�rtices de entrada
struct VertexIn
{
    float3 Pos   : POSITION;
    float4 Color : COLOR;
    float2 Tex   : TEXCOORD;    
};

// estrutura dos v�rtices de sa�da
struct VertexOut
{
    float4 Pos   : SV_POSITION;
    float4 Color : COLOR;
    float2 Tex   : TEXCOORD;    
};

// programa principal do vertex shader
VertexOut main( VertexIn vIn )
{
    VertexOut vOut;

    // transforma v�rtices para coordenadas da tela
    vOut.Pos = mul(float4(vIn.Pos, 1.0f), WorldViewProj);
    
    // mant�m as cores inalteradas
    vOut.Color = vIn.Color;

    // mant�m as coordenadas da textura inalteradas
    vOut.Tex = vIn.Tex;

    return vOut;
}

//////////////////////////////////////////////////////////////////////////