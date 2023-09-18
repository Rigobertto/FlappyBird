#include "Coin.h"

// ---------------------------------------------------------------------------------

Coin::Coin(float posX, float posY, uint platType, Color tint) : color(tint)
{
    switch (platType)
    {
    case RED:  tileset = new TileSet("Resources/coins/red-coin.png", 16, 16, 5, 5); type = RED; break;
    case SILVER: tileset = new TileSet("Resources/coins/silver-coin.png", 16, 16, 5, 5); type = SILVER; break;
    case GOLD: tileset = new TileSet("Resources/coins/gold-coin.png", 16, 16, 5, 5); type = GOLD; break;
    case MEDAL: tileset = new TileSet("Resources/coins/medal.png", 16, 16, 5, 5); type = MEDAL; break;
    }
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
