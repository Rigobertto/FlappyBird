/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:     21 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background(float speed, Color tint) : color(tint)
{
    MoveTo(window->CenterX(), window->CenterY(), Layer::BACK);
    xB = x;
    this->speed = speed;
    // carrega imagens
    //imgF = new Image("Resources/floor/floor-level1.png"); // 480x584
    imgB = new Image("Resources/backgrounds/background-level1.png");

    
    backgB1 = new Sprite(imgB);
    backgB2 = new Sprite(imgB);
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
    
    delete imgB;
    delete backgB1;
    delete backgB2;
}

// -------------------------------------------------------------------------------

void Background::Update()
{
    // move sprites com velocidades diferentes
    xB -= speed * gameTime;
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
    // desenha pano de fundo
   

    // desenha prédios mais distantes
    backgB1->Draw(xB, y, Layer::LOWER, 1.0f, 0.0f, color);
    backgB2->Draw(xB + imgB->Width(), y, Layer::LOWER, 1.0f, 0.0f, color);
    
    // traz pano de fundo de volta para dentro da tela
    if (xB + imgB->Width()/2.0f < 0)
        xB += imgB->Width();

   
}

// -------------------------------------------------------------------------------
