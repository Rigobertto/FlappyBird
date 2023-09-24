
#include "Engine.h"
#include "NextStage.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Background.h"
#include "Scene.h"
#include "Animation.h"
#include "Level1.h"
#include "Level2.h"
#include "Level3.h"

// ----------------------------------------------------------------------
Scene* NextStage::scene = nullptr;

void NextStage::Init()
{
    scene = new Scene();
    nextstage = new Sprite("Resources/botoes/level-completed.png");

    string src = "Resources/backgrounds/start-screen.png";
    background = new Background(50, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);


    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile
    menu[0] = new Item(window->CenterX(), 375, 124, 57, 1, 2, NEXTLEVEL, "Resources/botoes/next-level.png");
    menu[1] = new Item(window->CenterX(), 450, 102, 25, 1, 2, HOMESMALL, "Resources/botoes/home-small.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);
}

// ----------------------------------------------------------------------

void NextStage::Update()
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
                case NEXTLEVEL:
                    GravityGuy::audio->Stop(MENU);
                    GravityGuy::NextLevel<Level1>();
                    break;
                case HOMESMALL:
                    GravityGuy::audio->Stop(MENU);
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

void NextStage::Draw()
{
    nextstage->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ----------------------------------------------------------------------

void NextStage::Finalize()
{
    delete background;
    delete mouse;
    delete nextstage;
}

// ----------------------------------------------------------------------

