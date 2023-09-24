#include "Coin.h"

// ---------------------------------------------------------------------------------

Coin::Coin(float posX, float posY)
{
    
    tileset = new TileSet("Resources/coins/coin.png", 32, 32, 5, 5);
    anim = new Animation(tileset, 0.125f, true);

    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Coin::~Coin()
{
    delete tileset;
    delete anim;
}

// -------------------------------------------------------------------------------

void Coin::Update()
{
    // move plataforma apenas no eixo x
    anim->NextFrame();
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
