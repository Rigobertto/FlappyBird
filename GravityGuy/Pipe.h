/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _FLAPPYBIRD_PIPE_H_
#define _FLAPPYBIRD_PIPE_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites

// ---------------------------------------------------------------------------------

enum PIPETYPES {GREENUP, GREENDOWN, FINISH, REDUP, REDDOWN, BLUEUP, BLUEDOWN, CIANUP, CIANDOWN};

// ---------------------------------------------------------------------------------

class Pipe : public Object
{
private:
    Sprite* pipe = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma

public:
    Pipe(float posX, float posY,
        uint platType,
        Color tint);                   // construtor    
    ~Pipe();                            // destrutor

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Pipe::Draw()
{
    pipe->Draw(x, y, z, 1.0f, 0.0f, color);
}

// ---------------------------------------------------------------------------------

#endif