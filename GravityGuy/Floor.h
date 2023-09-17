/**********************************************************************************
// Background (Arquivo de Cabeçalho)
//
// Criação:     21 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_FLOOR_H_
#define _GRAVITYGUY_FLOOR_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Floor : public Object
{
private:
    float xF;
    Image* imgF;                       // imagem de fundo frontal
    
    Sprite* backgF1;                   // pano de fundo dinâmico (frontal 1)
    Sprite* backgF2;                   // pano de fundo dinâmico (frontal 2)
   

    Color color;                        // cor do pano de fundo

public:
    Floor(string src, Color tint);             // construtor
    ~Floor();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif