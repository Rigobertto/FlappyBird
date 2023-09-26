#include "Coin.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"
#include "Player.h"
#include "GravityGuy.h"
#include "Pipe.h"

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

    type = COIN;
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

void Coin::OnCollision(Object* obj) {

    uint teste = obj->Type();
    
    if (nivel == 1) {
        Level1::scene->Delete(this, STATIC);
        coinslevel1 += 1;
    }
    else if (nivel == 2) {
        Level2::scene->Delete(this, STATIC);
        coinslevel2 += 1;
    }
    else if(nivel == 3) {
        Level3::scene->Delete(this, STATIC);
        coinslevel3 += 1;
    }
}
