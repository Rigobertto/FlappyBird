
#ifndef _FLAPPYBIRD_PLAYER_H_
#define _FLAPPYBIRD_PLAYER_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Types.h"                      // tipos espec�ficos da engine
#include "Object.h"                     // interface de Object
#include "Animation.h"                  // anima��o de sprites

// ------------------------------------------------------------------------------

enum Gravity {NORMAL,INVERTED};         // tipo da gravidade
enum Skin {REDBIRD,BLUEBIRD, YELLOWBIRD};
extern int nivel;
extern int coinslevel1;
extern int coinslevel2;
extern int coinslevel3;
// ---------------------------------------------------------------------------------

class Player : public Object
{
private:
    TileSet   * tileset;                // folha de sprites do personagem
    Animation * anim;                   // anima��o do personagem
    uint        gravity;                // gravidade atuando sobre o jogador
    int         level;                  // n�vel finalizado
    uint skin;
    
public:
    /*static int coinslevel1;
    static int coinslevel2;
    static int coinslevel3;*/
    bool goldmedal = false;
    bool bronzemedal = false;
    bool silvermedal = false;
    float jumpMax = 5000;
    float totalJump = 0;

    Player();                           // construtor
    ~Player();                          // destrutor

    void Reset();                       // volta ao estado inicial
    int Level();                        // �ltimo n�vel finalizado
    float Bottom();                     // coordenadas da base
    float Top();                        // coordenadas do topo
    bool keyCtrl = false;
    void OnCollision(Object * obj);     // resolu��o da colis�o
    void Update();                      // atualiza��o do objeto
    void Draw();                        // desenho do objeto

};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

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