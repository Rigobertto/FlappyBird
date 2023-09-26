
#include "Engine.h"
#include "GameOver.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Background.h"
#include "Scene.h"
#include "Animation.h"
#include "Level1.h"

// ----------------------------------------------------------------------
Scene* GameOver::scene = nullptr;

void GameOver::Init()
{
    scene = new Scene();
    gameover = new Sprite("Resources/botoes/gameover.png");

    string src = "Resources/backgrounds/start-screen.png";
    background = new Background(50, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);


    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile
    menu[0] = new Item(window->CenterX(), 350, 292, 29, 1, 2, PLAYAGAIN, "Resources/botoes/play-again.png");
    menu[1] = new Item(window->CenterX(), 400, 126, 29, 1, 2, HOME, "Resources/botoes/home.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);
}

// ----------------------------------------------------------------------

void GameOver::Update()
{

    scene->Update();

     // fecha a janela ao pressionar ESC
    if (window->KeyDown(VK_ESCAPE))
        window->Close();

    // atualiza objeto mouse
    mouse->Update();

    // destaca item selecionado
    for (int i = 0; i < MaxItens; i++)
    {
        if (scene->Collision(mouse, menu[i]))
        {
            menu[i]->Select();

            if (mouse->Clicked())
            {
                switch (menu[i]->Type())
                {
                case PLAYAGAIN:
                    nivel = 1;
                    coinslevel1 = 0;
                    coinslevel2 = 0;
                    coinslevel3 = 0;
                    GravityGuy::audio->Stop(MENU);
                    GravityGuy::player->Reset();
                    GravityGuy::NextLevel<Level1>();                  
                    break;
                case HOME:
                    nivel = 1;
                    coinslevel1 = 0;
                    coinslevel2 = 0;
                    coinslevel3 = 0;
                    GravityGuy::audio->Stop(MENU);
                    GravityGuy::player->Reset();
                    GravityGuy::NextLevel<Home>();
                    break;
                }
                break;
            }
        }
        else
        {
            menu[i]->UnSelect();
        }

        menu[i]->Update();
    }
}

// ----------------------------------------------------------------------

void GameOver::Draw()
{
    gameover->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    delete background;
    delete mouse;
    delete gameover;
}

// ----------------------------------------------------------------------

