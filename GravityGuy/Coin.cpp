#include "Coin.h"

// ---------------------------------------------------------------------------------

Coin::Coin(float posX, float posY, uint platType, Color tint) : color(tint)
{
    switch (platType)
    {
    case COIN:  tileset = new TileSet("Resources/coins/coin.png", 32, 32, 5, 5); type = COIN; break;
    case SILVER: tileset = new TileSet("Resources/coins/silver-medal.png", 88, 88, 1, 1); type = SILVER; break;
    case GOLD: tileset = new TileSet("Resources/coins/gold-medal.png", 88, 88, 1, 1); type = GOLD; break;
    case BRONZE: tileset = new TileSet("Resources/coins/bronze-medal.png", 88, 88, 1, 1); type = BRONZE; break;
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
