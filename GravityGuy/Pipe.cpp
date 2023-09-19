#include "Pipe.h"

// ---------------------------------------------------------------------------------

Pipe::Pipe(float posX, float posY, uint platType, Color tint) : color(tint)
{
    switch (platType)
    {
    case GREENUP:  pipe = new Sprite("Resources/pipes/green-pipe-up.png"); type = GREENUP; break;
    case GREENDOWN: pipe = new Sprite("Resources/pipes/green-pipe-down.png"); type = GREENDOWN; break;

    case FINISH: pipe = new Sprite("Resources/Finish.png"); type = FINISH; break;

    case REDUP: pipe = new Sprite("Resources/pipes/red-pipe-up.png"); type = REDUP; break;
    case REDDOWN: pipe = new Sprite("Resources/pipes/red-pipe-down.png"); type = REDDOWN; break;

    case BLUEUP: pipe = new Sprite("Resources/pipes/blue-pipe-up.png"); type = BLUEUP; break;
    case BLUEDOWN: pipe = new Sprite("Resources/pipes/blue-pipe-down.png"); type = BLUEDOWN; break;

    case CIANUP: pipe = new Sprite("Resources/pipes/cian-pipe-up.png"); type = CIANUP; break;
    case CIANDOWN: pipe = new Sprite("Resources/pipes/cian-pipe-down.png"); type = CIANDOWN; break;
    }

    BBox(new Rect(-pipe->Width() / 2.0f,
        -pipe->Height() / 2.0f,
        pipe->Width() / 2.0f,
        pipe->Height() / 2.0f));

    MoveTo(posX, posY, Layer::MIDDLE);
}

// ---------------------------------------------------------------------------------

Pipe::~Pipe()
{
    delete pipe;
}

// -------------------------------------------------------------------------------

void Pipe::Update()
{
    // move plataforma apenas no eixo x
    Translate(-200.0f * gameTime, 0);
}

// -------------------------------------------------------------------------------
