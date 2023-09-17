/**********************************************************************************
// Item (Arquivo de Cabeçalho)
//
// Criação:     14 Mai 2012
// Atualização: 31 Ago 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Define um item de menu
//
**********************************************************************************/

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