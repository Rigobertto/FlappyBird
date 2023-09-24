
#ifndef _FLAPPYBIRD_PLAYER_H_
#define _FLAPPYBIRD_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclusões

#include "Types.h"                      // tipos específicos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // animação de sprites

// ------------------------------------------------------------------------------

enum Gravity {NORMAL,INVERTED};         // tipo da gravidade
enum Skin {REDBIRD,BLUEBIRD, YELLOWBIRD};

// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // animação do personagem
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // nível finalizado
    uint skin;
    
public:
    float* coinslevel1 = 0;
    float* coinslevel2 = 0;
    float* coinslevel3 = 0;
    bool goldmedal = false;
    bool bronzemedal = false;
    bool silvermedal = false;

    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // último nível finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo

    void OnCollision(Object * obj);     // resolução da colisão
    void Update();                      // atualização do objeto
    void Draw();                        // desenho do objeto
};

// ---------------------------------------------------------------------------------
// Função Membro Inline

inline int Player::Level()
{ return level; }

inline float Player::Bottom()
{ return y + tileset->Height()/2; }

inline float Player::Top()
{ return y - tileset->Height()/2; }

inline void Player::Draw()
{ anim->Draw(x, y, z); }

// ---------------------------------------------------------------------------------

#endif