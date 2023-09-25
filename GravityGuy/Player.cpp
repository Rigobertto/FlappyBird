
#include "Player.h"
#include "GravityGuy.h"
#include "Pipe.h"
// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/player/yellow-bird.png", 53, 38, 1, 3);
    anim = new Animation(tileset, 0.25f, true);

    // sequências de animação do player
    uint jump[2] = {1, 2};
    uint normal[1] = {0};

    anim->Add(INVERTED, jump, 2);
    anim->Add(NORMAL, normal, 1);

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
    if (obj->Type() == FINISH)
    {
        // chegou ao final do nível
        level++;
    }
    else
    {
        // mantém personagem em cima da plataforma
        //if (gravity == NORMAL)
          //  MoveTo(window->CenterX(), obj->Y() - 32);
        //else
            //MoveTo(window->CenterX(), obj->Y() + 32);
    }

        // toca efeito sonoro
        //GravityGuy::audio->Play(TRANSITION);

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