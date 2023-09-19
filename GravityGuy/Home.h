/**********************************************************************************
// Home (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Tela de abertura do jogo
//
**********************************************************************************/

#ifndef _FLAPPYBIRD_HOME_H_
#define _FLAPPYBIRD_HOME_H_

// ------------------------------------------------------------------------------
// Inclusões

#include "Game.h"
#include "Sprite.h"
#include "TileSet.h"
#include "Animation.h"
#include "Item.h"
#include "Mouse.h"
#include "Scene.h"
#include "Background.h"

// ------------------------------------------------------------------------------

enum MenuID { PLAY, LEVELS, OPTIONS, ABOUT, EXIT };

class Home : public Game
{
private:
    static const int MaxItens = 5;

    Mouse* mouse = nullptr;         // objeto mouse
    Sprite* logo = nullptr;
    Background* background = nullptr;
    TileSet * tileset = nullptr;    // tileset da animação
    Animation * anim = nullptr;     // animação do menu
    Item * menu[MaxItens] = { 0, 0, 0, 0, 0 };    // itens do menu

public:
    static Scene* scene;           // cena do nível

    void Init();                    // inicia nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza nível
};

// -----------------------------------------------------------------------------

#endif