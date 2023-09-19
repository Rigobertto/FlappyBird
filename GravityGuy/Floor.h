
#ifndef _FLAPPYBIRD_FLOOR_H_
#define _FLAPPYBIRD_FLOOR_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Sprite.h"                     // background � composto por sprites

// ---------------------------------------------------------------------------------

class Floor : public Object
{
private:
    float xF;
    Image* imgF;                       // imagem de fundo frontal
    
    Sprite* backgF1;                   // pano de fundo din�mico (frontal 1)
    Sprite* backgF2;                   // pano de fundo din�mico (frontal 2)
   

    Color color;                        // cor do pano de fundo

public:
    Floor(string src, Color tint);             // construtor
    ~Floor();                      // destrutor

    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif