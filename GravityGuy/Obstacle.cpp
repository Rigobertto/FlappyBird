/**********************************************************************************
// Platform (Código Fonte)
//
// Criação:     21 Abr 2012
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Plataformas do jogo
//
**********************************************************************************/

#include "Obstacle.h"

// ---------------------------------------------------------------------------------

Obstacle::Obstacle(float posX, float posY, uint platType, Color tint) : color(tint)
{
    switch (platType)
    {
    case UP:  obstacle = new Sprite("Resources/SmallGray.png"); type = UP; break;
    case DOWN: obstacle = new Sprite("Resources/MediumGray.png"); type = DOWN; break;
    case FINISH: obstacle = new Sprite("Resources/Finish.png"); type = FINISH; break;
    }

    BBox(new Rect(-obstacle->Width() / 2.0f,
        -obstacle->Height() / 2.0f,
        obstacle->Width() / 2.0f,
        obstacle->Height() / 2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Obstacle::~Obstacle()
{
    delete obstacle;
}

// -------------------------------------------------------------------------------

void Obstacle::Update()
{
    // move plataforma apenas no eixo x
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
