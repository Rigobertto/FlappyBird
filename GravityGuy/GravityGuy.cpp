

#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "GameOver.h"
#include "Level1.h"
#include "NextStage.h"

// ------------------------------------------------------------------------------

// inicializa membros est�ticos da classe
Game*   GravityGuy::level = nullptr;
Player* GravityGuy::player = nullptr;
Audio*  GravityGuy::audio = nullptr;
bool    GravityGuy::viewBBox = false;
bool GravityGuy::gameover = false;

// ------------------------------------------------------------------------------

void GravityGuy::Init() 
{
    // cria sistema de �udio
    audio = new Audio();
    audio->Add(MENU, "Resources/sounds/Musicainicio.wav");
    audio->Add(MUSIC, "Resources/sounds/StardewValley.wav");
    audio->Add(TRANSITION, "Resources/Transition.wav");
    audio->Add(MOEDA, "Resources/sounds/moeda.wav");
    audio->Add(PULO, "Resources/sounds/pulo.wav");

    // bounding box n�o vis�vel
    viewBBox = false;

    // cria jogador
    player = new Player();

    // inicializa n�vel de abertura do jogo
    level = new Home();
    level->Init();
}

// ------------------------------------------------------------------------------

void GravityGuy::Update()
{
    if (gameover)
    {
        GravityGuy::NextLevel<GameOver>();
        gameover = false;
    }

    // habilita/desabilita visualiza��o da bounding box
    if (window->KeyPress('B'))
        viewBBox = !viewBBox;    

    // atualiza n�vel
    level->Update();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Draw()
{
    // desenha n�vel
    level->Draw();
} 

// ------------------------------------------------------------------------------

void GravityGuy::Finalize()
{
    level->Finalize();

    delete player;
    delete audio;
    delete level;
}


// ------------------------------------------------------------------------------
//                                  WinMain                                      
// ------------------------------------------------------------------------------

int APIENTRY WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow)
{
    Engine * engine = new Engine();

    // configura o motor
    engine->window->Mode(WINDOWED);
    engine->window->Size(960, 640);
    engine->window->Color(84, 192, 201);
    engine->window->Title("Flappy Cat");
    engine->window->Icon(IDI_ICON);
    engine->window->Cursor(IDC_CURSOR);
    //engine->graphics->VSync(true);

    // inicia o jogo
    int status = engine->Start(new GravityGuy());

    delete engine;
    return status;
}

// ----------------------------------------------------------------------------

