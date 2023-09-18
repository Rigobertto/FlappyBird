#include "Pipe.h"

// ---------------------------------------------------------------------------------

Pipe::Pipe(float posX, float posY, uint platType, Color tint) : color(tint)
{
    switch (platType)
    {
    case UP:  pipe = new Sprite("Resources/pipes/green-pipe-up.png"); type = UP; break;
    case DOWN: pipe = new Sprite("Resources/pipes/green-pipe-down.png"); type = DOWN; break;
    case FINISH: pipe = new Sprite("Resources/Finish.png"); type = FINISH; break;
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
