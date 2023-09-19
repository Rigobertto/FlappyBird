#ifndef _FLAPPYBIRD_LEVEL3_H_
#define _FLAPPYBIRD_LEVEL3_H_

// ------------------------------------------------------------------------------
// Inclusões

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
    static Scene* scene;           // cena do nível

    void Init();                    // inicialização do nível
    void Update();                  // atualiza lógica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finalização do nível
};

// -----------------------------------------------------------------------------

#endif
