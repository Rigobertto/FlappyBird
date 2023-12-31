
#include "GravityGuy.h"
#include "Home.h"
#include "Level1.h"
#include "Level2.h"
#include "level3.h"
#include "GameOver.h"
#include "Player.h"
#include "Pipe.h"
#include "Background.h"
#include "Floor.h"
#include "Coin.h"
#include "NextStage.h"

#include <string>
#include <fstream>
#include <iostream>
using std::ifstream;
using std::string;
using namespace std;

// ------------------------------------------------------------------------------
// Inicializa membros est�ticos da classe

Scene* Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
    // cria gerenciador de cena
    scene = new Scene();

    // pano de fundo do jogo
    string src = "Resources/backgrounds/background-level-2.png";
    backg = new Background(150, Color{ 1,1,1,1 }, src);
    scene->Add(backg, STATIC);

    floor = new Floor("Resources/floor/floor-level1.png", Color{ 1,1,1,1 });
    scene->Add(floor, STATIC);

    // adiciona jogador na cena
    scene->Add(GravityGuy::player, MOVING);

    //-----------------------
    //Moedas
    //-----------------------
    Coin* coin;

    //float coinX, coinY;
    float xx = 0;
    float yy = 0;
    char caractere;
    bool primeiraLinha = true;

    ifstream finC;
    finC.open("coins-level2.txt");

    if (finC.is_open()) {
        char caractere;
        while (finC.get(caractere)) {
            if (primeiraLinha && caractere == '\n') {
                primeiraLinha = false;
                continue;
            }

            if (caractere == 'M') {
                xx = xx + 32;
            }
            else if (caractere == 'O') {
                coin = new Coin(xx + 16, yy + 16);
                scene->Add(coin, STATIC);
                xx = xx + 32;
            }
            else if (caractere == '\n') {
                yy = yy + 32;
                xx = 0;
            }
            else if (caractere == ' ') {
                continue; // Ignora os espa�os e continua com a pr�xima itera��o
            }
        }

        finC.close();
    }
    else {
        cout << "Erro ao abrir o arquivo." << std::endl;
    }




    // ----------------------
    // plataformas
    // ----------------------
    Pipe* pipe;
    float posX, posY;
    uint  platType;
    Color white{ 1,1,1,1 };

    ifstream fin;
    fin.open("Level2.txt");

    fin >> posX;
    while (!fin.eof())
    {
        if (fin.good())
        {
            // l� linha com informa��es da plataforma
            fin >> posY; fin >> platType;
            pipe = new Pipe(posX, posY, platType, white);
            scene->Add(pipe, STATIC);
        }
        else
        {
            // ignora coment�rios
            fin.clear();
            char temp[80];
            fin.getline(temp, 80);
        }

        fin >> posX;
    }
    fin.close();

    // ----------------------

    // inicia com m�sica
    GravityGuy::audio->Frequency(MUSIC, 0.94f);
    GravityGuy::audio->Frequency(TRANSITION, 1.0f);
    GravityGuy::audio->Play(MUSIC);
}

// ------------------------------------------------------------------------------

void Level2::Update()
{
    if (window->KeyPress(VK_ESCAPE))
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<Home>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Bottom() < 0 || GravityGuy::player->Top() > window->Height())
    {
        GravityGuy::audio->Stop(MUSIC);
        GravityGuy::NextLevel<GameOver>();
        GravityGuy::player->Reset();
    }
    else if (GravityGuy::player->Level() == 2 || window->KeyPress('N'))
    {
        nivel = 2;
        GravityGuy::NextLevel<NextStage>();
    }
    else
    {
        scene->Update();
        scene->CollisionDetection();
    }
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
    backg->Draw();
    scene->Draw();

    if (GravityGuy::viewBBox)
        scene->DrawBBox();
}

// ------------------------------------------------------------------------------

void Level2::Finalize()
{
    scene->Remove(GravityGuy::player, MOVING);
    delete scene;
}

// ------------------------------------------------------------------------------