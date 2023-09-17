/**********************************************************************************
// Platform (Arquivo de Cabeçalho)
//
// Criação:     21 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#ifndef _GRAVITYGUY_OBSTACLE_H_
#define _GRAVITYGUY_OBSTACLE_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites

// ---------------------------------------------------------------------------------

enum PLATTYPES { UP, DOWN, FINISH };

// ---------------------------------------------------------------------------------

class Obstacle : public Object
{
private:
    Sprite* obstacle = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma

public:
    Obstacle(float posX, float posY,
        uint platType,
        Color tint);                   // construtor    
    ~Obstacle();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Obstacle::Draw()
{
    obstacle->Draw(x, y, z, 1.0f, 0.0f, color);
}

// ---------------------------------------------------------------------------------

#endif