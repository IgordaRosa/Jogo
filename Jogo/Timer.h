//////////////////////////////////////////////////////////////////////////

#ifndef TIMER
#define TIMER

//////////////////////////////////////////////////////////////////////////

#include <windows.h>            // acesso ao contador de alta precis�o do Windows

//////////////////////////////////////////////////////////////////////////
class Timer
{
private:
    LARGE_INTEGER start, end;   // valores de in�cio e fim do contador
    LARGE_INTEGER freq;         // freq��ncia do contador
    bool stoped;                // estado da contagem
    
public:
    Timer();                    // constructor

    void  Start();              // inicia/retoma contagem do tempo
    void  Stop();               // p�ra contagem do tempo
    float Reset();              // reinicia contagem e retorna tempo transcorrido
    float Elapsed();            // retorna tempo transcorrido em segundos    
    bool  Elapsed(float secs);  // verifica se transcorreu "secs" segundos
}; 

//////////////////////////////////////////////////////////////////////////
inline bool Timer::Elapsed(float secs)
{ return (Elapsed() >= secs ? true : false); }

//////////////////////////////////////////////////////////////////////////

#endif