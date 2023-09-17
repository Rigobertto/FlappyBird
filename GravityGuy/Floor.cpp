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

#include "Floor.h"

// ---------------------------------------------------------------------------------

Floor::Floor(string src, Color tint) : color(tint)
{
    MoveTo(480, 584, Layer::FRONT);
    xF = x;

    // carrega imagens
    imgF = new Image(src); // 480x584

    // cria sprites do plano de fundo
    backgF1 = new Sprite(imgF);
    backgF2 = new Sprite(imgF);

    BBox(new Rect(-backgF1->Width() / 2, -backgF1->Height() / 2, backgF1->Width() / 2, backgF1->Height() / 2));
}

// ---------------------------------------------------------------------------------

Floor::~Floor()
{
    delete imgF;
    delete backgF1;
    delete backgF2;
}

// -------------------------------------------------------------------------------

void Floor::Update()
{
    // move sprites com velocidades diferentes
    xF -= 200 * gameTime;
}

// -------------------------------------------------------------------------------

void Floor::Draw()
{
    // desenha pano de fundo

    // desenha prédios mais próximos
    /*backgF1->Draw(xF, y, Layer::FRONT, 1.0f, 0.0f, color);
    backgF2->Draw(xF + imgF->Width(), window->Height() / 2.0f, Layer::FRONT, 1.0f, 0.0f, color);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width() / 2.0f < 0)
        xF += imgF->Width();*/

    //desenha prédios mais próximos
    backgF1->Draw(xF, y, Layer::MIDDLE);
    backgF2->Draw(xF + imgF->Width(), 584, Layer::MIDDLE);

    // traz pano de fundo de volta para dentro da tela
    if (xF + imgF->Width() / 2 < 0) {
        xF += imgF->Width();
        //img
    }
}

// -------------------------------------------------------------------------------
