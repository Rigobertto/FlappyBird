
#ifndef _FLAPPYBIRD_COIN_H_
#define _FLAPPYBIRD_COIN_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites
#include "Animation.h"   
#include "TileSet.h"   
// ---------------------------------------------------------------------------------

//enum COINTYPES { COIN, SILVER, GOLD, BRONZE };

// ---------------------------------------------------------------------------------

class Coin : public Object
{
private:
    TileSet * tileset = nullptr;            // sprite da plataforma
    Animation* anim = nullptr;

    //Color color;                            // cor da plataforma

public:
    
    Coin(float posX, float posY);                 // construtor    
    ~Coin();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object * obj);
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Coin::Draw()
{
    anim->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif