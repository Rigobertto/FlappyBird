
#include "Player.h"
#include "GravityGuy.h"
#include "Pipe.h"
// ---------------------------------------------------------------------------------

Player::Player()
{
    tileset = new TileSet("Resources/player/yellow-bird.png", 53, 38, 1, 3);
    anim = new Animation(tileset, 0.25f, true);

    // sequ�ncias de anima��o do player
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

    // posi��o inicial
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
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
    MoveTo(window->CenterX(), 24.0f, Layer::FRONT);
    gravity = NORMAL;
    level = 0;
}


// ---------------------------------------------------------------------------------

void Player::OnCollision(Object * obj)
{
    if (obj->Type() == FINISH)
    {
        // chegou ao final do n�vel
        level++;
    }
    else
    {
        // mant�m personagem em cima da plataforma
        if (gravity == NORMAL)
            MoveTo(window->CenterX(), obj->Y() - 32);
        else
            MoveTo(window->CenterX(), obj->Y() + 32);
    }

    // ----------------------------------------------------------
    // Processa teclas pressionadas
    // ----------------------------------------------------------
    // jogador s� pode alterar a gravidade enquanto estiver
    // em cima de uma plataforma, n�o � poss�vel a mudan�a no ar
    // ----------------------------------------------------------

    if (window->KeyPress(VK_SPACE))
    {
        gravity = !gravity;

        // toca efeito sonoro
        GravityGuy::audio->Play(TRANSITION);

        // tira player da plataforma para evitar 
        // detec��o de colis�o no quadro seguinte
        if (gravity == NORMAL)
            Translate(0, 12);
        else
            Translate(0 , -12);
    }
}

// ---------------------------------------------------------------------------------

void Player::Update()
{
    // a��o da gravidade sobre o personagem
    if (gravity == NORMAL)    
        Translate(0, 300 * gameTime);
    else
        Translate(0, -300 * gameTime);

    // atualiza anima��o
    anim->Select(gravity);
    anim->NextFrame();
}

// ---------------------------------------------------------------------------------