/**********************************************************************************
// GameOver (Arquivo de Cabe�alho)
// 
// Cria��o:     14 Fev 2013
// Atualiza��o: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descri��o:   Fim do jogo
//              
**********************************************************************************/

#ifndef _FLAPPYBIRD_GAMEOVER_H_
#define _FLAPPYBIRD_GAMEOVER_H_

// ------------------------------------------------------------------------------

#include "Game.h"
#include "Sprite.h"
#include "Background.h"
#include "Scene.h"
#include "TileSet.h"
#include "Animation.h"
#include "Item.h"
#include "Mouse.h"

// ------------------------------------------------------------------------------

enum MenuGameOver { PLAYAGAIN, HOME };

class GameOver : public Game
{
private:
    static const int MaxItens = 2;

    Mouse* mouse = nullptr;         // objeto mouse
    Sprite* gameover = nullptr;       // pano de fundo
    Background* background = nullptr;
    Item* menu[MaxItens] = { 0, 0 };

public:
    static Scene* scene;

    void Init();                    // inicializa��o do n�vel
    void Update();                  // l�gica da tela de fim
    void Draw();                    // desenho da tela
    void Finalize();                // finaliza��o do n�vel
};

// ------------------------------------------------------------------------------

#endif