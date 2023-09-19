#ifndef _FLAPPYBIRD_LEVEL3_H_
#define _FLAPPYBIRD_LEVEL3_H_

// ------------------------------------------------------------------------------
// Inclus�es

#include "Game.h"
#include "Scene.h"
#include "Player.h"
#include "Background.h"
#include "Floor.h"

// ------------------------------------------------------------------------------

class Level3 : public Game
{
private:
    Background* backg = nullptr;   // pano de fundo animado
    Floor* floor = nullptr;

public:
    static Scene* scene;           // cena do n�vel

    void Init();                    // inicializa��o do n�vel
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza��o do n�vel
};

// -----------------------------------------------------------------------------

#endif
