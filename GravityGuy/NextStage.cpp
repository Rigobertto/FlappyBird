
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
#include <iostream>
#include <string>

// ----------------------------------------------------------------------
Scene* NextStage::scene = nullptr;

void NextStage::Init()
{
    scene = new Scene();
    nextstage = new Sprite("Resources/botoes/level-completed.png");

    string src = "Resources/backgrounds/start-screen.png";
    background = new Background(50, Color{ 1,1,1,1 }, src);
    scene->Add(background, STATIC);

    // cria fontes
    upheaval = new Font("Resources/font/upheaval.png");
    upheaval->Spacing("Resources/font/upheaval.dat");
    upheaval->Spacing(120);

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
                    if (nivel == 1) {
                        nivel = 2;
                        GravityGuy::NextLevel<Level2>();
                    }
                    else if (nivel == 2) {
                        nivel = 3;
                        GravityGuy::NextLevel<Level3>();
                    }
                    break;
                case HOMESMALL:
                    nivel = 1;
                    coinslevel1 = 0;
                    coinslevel2 = 0;
                    coinslevel3 = 0;
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
    Color vermelho(0.97f, 0.47f, 0.36f, 1.0f);
    Color creme(0.94f, 0.91f, 0.76f, 1.0f);
    
    nextstage->Draw(window->CenterX(), window->CenterY(), Layer::FRONT);

    if (nivel == 1) {
        
        string numeroString = std::to_string(coinslevel1);
        upheaval->Draw(600, 403, "x" + numeroString, creme, Layer::FRONT, 0.2);
        upheaval->Draw(600, 400, "x" + numeroString, vermelho, Layer::FRONT, 0.2);
    }
    else if (nivel == 2) {
        
        string numeroString = std::to_string(coinslevel2);
        upheaval->Draw(600, 403, "x" + numeroString, creme, Layer::FRONT, 0.2);
        upheaval->Draw(600, 400, "x" + numeroString, vermelho, Layer::FRONT, 0.2);
    }
    else if (nivel == 3) {
        
        string numeroString = std::to_string(coinslevel3);
        upheaval->Draw(600, 403, "x" + numeroString, creme, Layer::FRONT, 0.2);
        upheaval->Draw(600, 400, "x" + numeroString, vermelho, Layer::FRONT, 0.2);
    }
    
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ----------------------------------------------------------------------

void NextStage::Finalize()
{
    delete upheaval;
    delete background;
    delete mouse;
    delete nextstage;
}

// ----------------------------------------------------------------------

