/**********************************************************************************
// GameOver (Arquivo de Cabeçalho)
// 
// Criação:     14 Fev 2013
// Atualização: 04 Set 2023
// Compilador:  Visual C++ 2022
//
// Descrição:   Fim do jogo
//
**********************************************************************************/

#include "Engine.h"
#include "GameOver.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Background.h"
#include "Scene.h"
#include "Animation.h"

// ----------------------------------------------------------------------
Scene* GameOver::scene = nullptr;
void GameOver::Init()
{
    scene = new Scene();
    gameover = new Sprite("Resources/botoes/gameover.png");

    background = new Background(50, Color{ 1,1,1,1 });
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
    if (window->KeyPress(VK_ESCAPE) || window->KeyPress(VK_RETURN))
        GravityGuy::NextLevel<Home>();
    scene->Update();
    //anim->NextFrame();
    if (window->KeyPress(VK_RETURN))
    {
        GravityGuy::audio->Stop(MENU);
        GravityGuy::NextLevel<Home>();
    }
    else
    {
        //anim->NextFrame();
    }

    // atualiza objeto mouse

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
                    GravityGuy::audio->Stop(MENU);
                    GravityGuy::NextLevel<Home>();
                    break;
                case HOME: break;
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
    //background->Draw();
    gameover->Draw(window->CenterX(), window->CenterY(), Layer::MIDDLE);
    //anim->Draw(window->CenterX(), 200, Layer::FRONT);
    //desenha itens do menu
    scene->Draw();
}

// ----------------------------------------------------------------------

void GameOver::Finalize()
{
    //delete menu;
    delete background;
    delete mouse;
    delete gameover;
}

// ----------------------------------------------------------------------

