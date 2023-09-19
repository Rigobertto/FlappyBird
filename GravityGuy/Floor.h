
#ifndef _FLAPPYBIRD_FLOOR_H_
#define _FLAPPYBIRD_FLOOR_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background é composto por sprites

// ---------------------------------------------------------------------------------

class Floor : public Object
{
private:
    float xF;
    Image* imgF;                       // imagem de fundo frontal
    
    Sprite* backgF1;                   // pano de fundo dinâmico (frontal 1)
    Sprite* backgF2;                   // pano de fundo dinâmico (frontal 2)
   

    Color color;                        // cor do pano de fundo

public:
    Floor(string src, Color tint);             // construtor
    ~Floor();                      // destrutor

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif