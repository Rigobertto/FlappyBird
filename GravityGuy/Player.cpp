
#include "Player.h"
#include "GravityGuy.h"
#include "Pipe.h"
#include "Coin.h"
#include "Level1.h"
#include "NextStage.h"
#include "GameOver.h"
// ---------------------------------------------------------------------------------

//int* Player::coinslevel1 = 0;
//int* Player::coinslevel2 = 0;
int nivel = 1;
int coinslevel1 = 0;
int coinslevel2 = 0;
int coinslevel3 = 0;
//int* Player::coinslevel3 = 0;

Player::Player()
{
    tileset = new TileSet("Resources/player/yellow-bird.png", 53, 38, 1, 3);
    anim = new Animation(tileset, 0.25f, true);
    coinslevel1 = 0;
    coinslevel2 = 0;
    coinslevel3 = 0;
    // sequências de animação do player
    uint jump[3] = {0, 1, 2};
    uint normal[3] = {0, 1, 2};

    anim->Add(INVERTED, jump, 3);
    anim->Add(NORMAL, normal, 3);

    // cria bounding box
    BBox(new Rect(
        -1.0f * tileset->TileWidth() / 2.0f,
        -1.0f * tileset->TileHeight() / 2.0f,
        tileset->TileWidth() / 2.0f,
        tileset->TileHeight() / 2.0f));
    
    // inicializa estado do player
    gravity = NORMAL;  
    level = 0;

    // posição inicial
    MoveTo(190.0f, window->CenterY(), Layer::FRONT);
}

// ---------------------------------------------------------------------------------

Player::~Player()
{
    delete anim;
    delete tileset;    
}

// ---------------------------------------------------------------------------------

void Player::Reset()
{
    // volta ao estado inicial
    MoveTo(190.0f, window->CenterY(), Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == GREENDOWN || obj->Type() == GREENUP)
    {
        GravityGuy::NextLevel<GameOver>();
    }

    /*if (obj->Type() == FINISH)
    {
        // chegou ao final do nível
        level++;
    }*/

    {
        // mantém personagem em cima da plataforma
        //if (gravity == NORMAL)
          //  MoveTo(window->CenterX(), obj->Y() - 32);
        //else
            //MoveTo(window->CenterX(), obj->Y() + 32);
    }

        // toca efeito sonoro
        //GravityGuy::audio->Play(TRANSITION);
    //if (obj->Type() == COIN) {
        //Level1::scene->Delete(obj, STATIC);
    //}
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    anim->NextFrame();

    if (gravity == NORMAL)
        Translate(0, 200 * gameTime);
 

    if (totalJump < jumpMax && window->KeyDown(VK_SPACE)) {
        Translate(0, -1000 * gameTime);
        totalJump += 600;
    }
    else if ( window->KeyUp(VK_SPACE)) {
        totalJump = 0;
        
    }

}

// ---------------------------------------------------------------------------------