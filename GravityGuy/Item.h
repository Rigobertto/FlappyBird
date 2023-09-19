
#ifndef _FLAPPYBIRD_ITEM_H_
#define _FLAPPYBIRD_ITEM_H_

// ---------------------------------------------------------------------------------

#include "Object.h"
#include "Animation.h"
#include "TileSet.h"
#include "Types.h"

// ---------------------------------------------------------------------------------

enum MenuState { SELECTED, NOTSELECTED };

// ---------------------------------------------------------------------------------

class Item : public Object
{
private:
    TileSet* tileset;                // folha de sprites da animação
    Animation* animation;              // animação do menu

public:
    Item(float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile);
    ~Item();

    void Select();                      // seleciona menu
    void UnSelect();                    // desmarca seleção

    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------

#endif