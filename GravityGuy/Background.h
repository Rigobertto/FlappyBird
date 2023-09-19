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

#ifndef _FLAPPYBIRD_BACKGROUND_H_
#define _FLAPPYBIRD_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xB;                       // posição horizontal dos sprites
    Image * imgB;                       // imagem de fundo traseira    

    Sprite * backgB1;                   // pano de fundo dinâmico (traseiro 1)
    Sprite * backgB2;                   // pano de fundo dinâmico (traseiro 2)

    Color color;                        // cor do pano de fundo
    float speed = 0;

public:
    Background(float speed, Color tint, string src); // construtor
    ~Background();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif