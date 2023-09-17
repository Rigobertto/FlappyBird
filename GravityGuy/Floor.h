/**********************************************************************************
// Background (Arquivo de Cabe�alho)
//
// Cria��o:     21 Abr 2012
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_FLOOR_H_
#define _GRAVITYGUY_FLOOR_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Floor : public Object
{
private:
    float xF;
    Image* imgF;                       // imagem de fundo frontal
    
    Sprite* backgF1;                   // pano de fundo din�mico (frontal 1)
    Sprite* backgF2;                   // pano de fundo din�mico (frontal 2)
   

    Color color;                        // cor do pano de fundo

public:
    Floor(string src, Color tint);             // construtor
    ~Floor();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif