
#ifndef _FLAPPYBIRD_PIPE_H_
#define _FLAPPYBIRD_PIPE_H_

// ---------------------------------------------------------------------------------

#include "Types.h"                                      // tipos específicos da engine
#include "Object.h"                                     // interface de Object
#include "Sprite.h"                                     // desenho de sprites


// ---------------------------------------------------------------------------------

enum PIPETYPES {GREENUP, GREENDOWN, FINISH, REDUP, REDDOWN, BLUEUP, BLUEDOWN, CIANUP, CIANDOWN};

// ---------------------------------------------------------------------------------

class Pipe : public Object
{
private:
    Sprite* pipe = nullptr;            // sprite da plataforma
    Color color;                            // cor da plataforma
    bool gameover = false;

public:
    Pipe(float posX, float posY,
        uint platType,
        Color tint);                   // construtor    
    ~Pipe();                            // destrutor

    void Update();                          // atualização do objeto
    void Draw();                            // desenho do objeto
    void OnCollision(Object * obj);
    bool isCollision();
    
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline void Pipe::Draw()
{
    pipe->Draw(x, y, z, 1.0f, 0.0f, color);
}

// ---------------------------------------------------------------------------------

#endif