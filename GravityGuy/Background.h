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

#ifndef _FLAPPYBIRD_BACKGROUND_H_
#define _FLAPPYBIRD_BACKGROUND_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Background : public Object
{
private:
    float xB;                       // posi��o horizontal dos sprites
    Image * imgB;                       // imagem de fundo traseira    

    Sprite * backgB1;                   // pano de fundo din�mico (traseiro 1)
    Sprite * backgB2;                   // pano de fundo din�mico (traseiro 2)

    Color color;                        // cor do pano de fundo
    float speed = 0;

public:
    Background(float speed, Color tint, string src); // construtor
    ~Background();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif