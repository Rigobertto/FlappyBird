
#ifndef _FLAPPYBIRD_MOUSE_H_
#define _FLAPPYBIRD_MOUSE_H_

// ---------------------------------------------------------------------------------

#include "Object.h"        
#include "Types.h" 
#include "Item.h"

// ---------------------------------------------------------------------------------

class Mouse : public Object
{
public:
    Mouse();            // construtor
    ~Mouse();           // destrutor

    bool Clicked();     // click do mouse
    void Update();      // atualização do objeto
    void Draw();        // desenho do objeto
}; 

// ---------------------------------------------------------------------------------

#endif