
#ifndef _FLAPPYBIRD_COIN_H_
#define _FLAPPYBIRD_COIN_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos espec�ficos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
#include "Animation.h"   
#include "TileSet.h"   
// ---------------------------------------------------------------------------------

enum COINTYPES { RED, SILVER, GOLD, MEDAL };

// ---------------------------------------------------------------------------------

class Coin : public Object
{
private:
    TileSet * tileset = nullptr;            // sprite da plataforma
    Animation* anim = nullptr;

    Color color;                            // cor da plataforma

public:
    Coin(float posX, float posY,
        uint platType,
        Color tint);                   // construtor    
    ~Coin();                            // destrutor

    void Update();                          // atualiza��o do objeto
    void Draw();                            // desenho do objeto
    void OnCollision();
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Coin::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif