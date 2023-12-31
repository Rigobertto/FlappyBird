
#ifndef _FLAPPYBIRD_H_
#define _FLAPPYBIRD_H_

// ---------------------------------------------------------------------------------

#include "Game.h"
#include "Audio.h"
#include "Player.h"
#include "Resources.h"
#include "Mouse.h"

// ------------------------------------------------------------------------------

enum Sounds {MENU, MUSIC, TRANSITION, MOEDA, PULO};
// ------------------------------------------------------------------------------

class GravityGuy : public Game
{
private:
    static Game * level;            // n�vel atual do jogo

public:
    static Player * player;         // jogador 
    static Audio * audio;           // sistema de �udio
    static bool viewBBox;           // estado da bounding box

    static bool gameover;
    void Init();                    // inicializa jogo
    void Update();                  // atualiza l�gica do jogo
    void Draw();                    // desenha jogo
    void Finalize();                // finaliza jogo

    template<class T>
    static void NextLevel()         // muda para pr�ximo n�vel do jogo
    {
        if (level)
        {
            level->Finalize();
            delete level;
            level = new T();
            level->Init();
        }
    };
};

// ---------------------------------------------------------------------------------

#endif