
#include "Engine.h"
#include "GravityGuy.h"
#include "Home.h"
#include "Level2.h"
#include "Level1.h"
#include "GameOver.h"
#include "Background.h"

// ------------------------------------------------------------------------------

Scene* Home::scene = nullptr;

void Home::Init()
{

    scene = new Scene();

    string src = "Resources/backgrounds/start-screen.png";
    background = new Background(50, Color{ 1,1,1,1 },src);
    scene->Add(background, STATIC);

    logo = new Sprite("Resources/botoes/logo2.png");
    tileset = new TileSet("Resources/player/yellow-bird.png", 53, 38, 3, 3);
    anim = new Animation(tileset, 0.20f, true);
    

    // cria objeto mouse
    mouse = new Mouse();
    scene->Add(mouse, MOVING);

    // cria itens de menu - float posX, float posY, float largura, float altura, int colunas, int quantidade, uint menuId, string imgFile
    menu[0] = new Item(window->CenterX(), 250, 122, 27, 1, 2, PLAY, "Resources/botoes/play.png");
    menu[1] = new Item(window->CenterX(), 300, 182, 27, 1, 2, LEVELS, "Resources/botoes/levels.png");
    menu[2] = new Item(window->CenterX(), 350,213, 27, 1, 2, OPTIONS, "Resources/botoes/options.png");
    menu[3] = new Item(window->CenterX(), 500, 130, 25, 1, 2, ABOUT, "Resources/botoes/about.png");
    menu[4] = new Item(window->CenterX(), 550, 103, 25, 1, 2, EXIT, "Resources/botoes/exit.png");

    // adiciona itens na cena
    for (int i = 0; i < MaxItens; ++i)
        scene->Add(menu[i], STATIC);

    GravityGuy::audio->Play(MENU, true);
}

// ------------------------------------------------------------------------------

void Home::Update()
{
    anim->NextFrame();
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
                    case PLAY: 
                        GravityGuy::audio->Stop(MENU);
                        GravityGuy::NextLevel<Level1>();                   
                        break;
                    case LEVELS: break;
                    case OPTIONS: break;
                    case ABOUT: break;
                    case EXIT: window->Close(); break;
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

// ------------------------------------------------------------------------------

void Home::Draw()
{
    //desenha a logo do jogo
    logo->Draw(window->CenterX(), 100, Layer::FRONT);

    //desenha o passaro
    anim->Draw(window->CenterX(), 200, Layer::FRONT);

    // desenha itens do menu
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
    
}

// ------------------------------------------------------------------------------

void Home::Finalize()
{
    delete background;
    delete logo;
    delete mouse;
    delete anim;
    delete tileset;
}

// ------------------------------------------------------------------------------