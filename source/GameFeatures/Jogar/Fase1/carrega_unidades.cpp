#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

vector <Unidade *> unidades_azul;
vector <Unidade *> unidades_vermelhas;
vector< vector <Hexagono*> > hexagonos;
SDL_Rect cutBox = { 32, 0, 32, 32};


void setar_soldado(Unidade *soldado, char cor[],string tipo,SDL_Surface *nome){
    soldado->hp = 200;
    soldado->atk = 100;
    soldado->def = 100;
    soldado->alcance = 1;
    soldado->ouro = 100;
    soldado->cor = cor;
    soldado->nome = nome;
    soldado->tipo = tipo;

}

void setar_helicoptero(Unidade *helicoptero, char cor[], string tipo, SDL_Surface *nome){
    helicoptero->hp = 300;
    helicoptero->atk = 400;
    helicoptero->def = 200;
    helicoptero->alcance = 4;
    helicoptero->ouro = 400;
    helicoptero->cor = cor;
    helicoptero->nome = nome;
    helicoptero->tipo = tipo;
}

void setar_metralhadora(Unidade *metralhadora, char cor[], string tipo,SDL_Surface *nome){
    metralhadora->hp = 100;
    metralhadora->atk = 200;
    metralhadora->def = 300;
    metralhadora->alcance = 3;
    metralhadora->ouro = 200;
    metralhadora->cor = cor;
    metralhadora->nome = nome;
    metralhadora->tipo = tipo;
}

void setar_tanque(Unidade *tanque, char cor[], string tipo, SDL_Surface *nome){
    tanque->hp = 400;
    tanque->atk = 300;
    tanque->def = 400;
    tanque->alcance = 2;
    tanque->ouro = 300;
    tanque->cor = cor;
    tanque->nome = nome;
    tanque->tipo = tipo;
}

void carrega_china(SDL_Surface *screen,string lado){

    string lado1("servidor");
    char cor[100] = "azul";
    int k;
    for(int i=0, j=1;i<10;i++,j+=30){
        k=i;
        string caminho = "source/GameFeatures/Jogar/Fase1/images/unidade_azul_direita1.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        string unidadea1 = "soldado";
        setar_soldado(soldado, cor, unidadea1, soldado1);
        unidades_azul.push_back(soldado);
        //if(i+2<=hexagonos.size()){
        BlitImage(screen,unidades_azul[i]->nome,hexagonos[i*2][3]->x,hexagonos[i*2][3]->y);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;

        caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_azul.png";
        SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
        BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);

    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/metralha_azul.png";
    SDL_Surface *metralhadora1 = load_Image(caminho, screen);
    Unidade *metralhadora = new Unidade();
    string unidadea2 = "metralhadora";
    setar_metralhadora(metralhadora, cor, unidadea2, metralhadora1);
    unidades_azul.push_back(metralhadora);

    BlitImage(screen,unidades_azul[10]->nome,hexagonos[6][4]->x,hexagonos[6][4]->y);
    hexagonos[6][4]->contem_unidade=1;
    hexagonos[6][4]->unidade = metralhadora;

    SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	drawCircle(screen, 20, 44, 137, blue);
	drawCircle(screen, 20, 78, 157, blue);
}

void carrega_eua(SDL_Surface *screen,string lado){

    string lado2("cliente");
    char cor[100] = "vermelha";

    for(int i=0;i<3;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_andando_esquerda.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        Unidade *soldado = new Unidade();
        string unidade = "soldado";
        setar_soldado(soldado, cor, unidade, soldado1);
        unidades_vermelhas.push_back(soldado);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/helicoptero_vermelha_esquerda1.png";
        SDL_Surface *helicoptero1 = load_Image(caminho, screen);
        Unidade *helicoptero = new Unidade();
        string unidade1 = "helicoptero";
        setar_helicoptero(helicoptero, cor, unidade1, helicoptero1);
        unidades_vermelhas.push_back(helicoptero);
    }

    for (int i=0;i<2;i++){
        string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
        SDL_Surface *metrapalhadora1 = load_Image(caminho, screen);
        Unidade *metralhadora = new Unidade();
        string unidade2 = "metralhadora";
        setar_metralhadora(metralhadora, cor, unidade2, metrapalhadora1);
        unidades_vermelhas.push_back(metralhadora);
    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_vermelha_esquerda1.png";
    SDL_Surface *tanque1 = load_Image(caminho, screen);
    Unidade *tanque = new Unidade();
    string unidade3 = "tanque";
    setar_tanque(tanque, cor, unidade3, tanque1);
    unidades_vermelhas.push_back(tanque);

    SDL_Rect dst = {hexagonos[2][12]->x, hexagonos[2][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[0]->nome, &cutBox,  screen, &dst);
    //BlitImage(screen,unidades_vermelhas[0]->nome,hexagonos[2][12]->x,hexagonos[2][12]->y);
    hexagonos[2][12]->unidade = unidades_vermelhas[0];
    hexagonos[2][12]->contem_unidade = 1;
    unidades_vermelhas[0]->x = hexagonos[2][12]->x;
    unidades_vermelhas[0]->y = hexagonos[2][12]->y;

    SDL_Rect d = {hexagonos[4][12]->x, hexagonos[4][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[1]->nome, &cutBox,  screen, &d);
    //BlitImage(screen,unidades_vermelhas[1]->nome,hexagonos[4][12]->x,hexagonos[4][12]->y);
    hexagonos[4][12]->unidade = unidades_vermelhas[1];
    hexagonos[4][12]->contem_unidade = 1;
    unidades_vermelhas[1]->x = hexagonos[4][12]->x;
    unidades_vermelhas[1]->y = hexagonos[4][12]->y;

    SDL_Rect ds = {hexagonos[6][12]->x, hexagonos[6][12]->y, 0, 0};
    SDL_BlitSurface(unidades_vermelhas[2]->nome, &cutBox,  screen, &ds);
    //BlitImage(screen,unidades_vermelhas[2]->nome,hexagonos[6][12]->x,hexagonos[6][12]->y);
    hexagonos[6][12]->unidade = unidades_vermelhas[2];
    hexagonos[6][12]->contem_unidade = 1;
    unidades_vermelhas[2]->x = hexagonos[6][12]->x;
    unidades_vermelhas[2]->y = hexagonos[6][12]->y;

    BlitImage(screen,unidades_vermelhas[3]->nome,hexagonos[8][12]->x,hexagonos[8][12]->y);
    hexagonos[8][12]->unidade = unidades_vermelhas[3];
    hexagonos[8][12]->contem_unidade = 1;
    unidades_vermelhas[3]->x = hexagonos[8][12]->x;
    unidades_vermelhas[3]->y = hexagonos[8][12]->y;

    BlitImage(screen,unidades_vermelhas[5]->nome,hexagonos[10][12]->x,hexagonos[10][12]->y);
    hexagonos[10][12]->unidade = unidades_vermelhas[4];
    hexagonos[10][12]->contem_unidade = 1;
    unidades_vermelhas[4]->x = hexagonos[10][12]->x;
    unidades_vermelhas[4]->y = hexagonos[10][12]->y;

    BlitImage(screen,unidades_vermelhas[6]->nome,hexagonos[14][12]->x,hexagonos[14][12]->y);
    hexagonos[14][12]->unidade = unidades_vermelhas[5];
    hexagonos[14][12]->contem_unidade = 1;
    unidades_vermelhas[5]->x = hexagonos[14][12]->x;
    unidades_vermelhas[5]->y = hexagonos[14][12]->y;

    BlitImage(screen,unidades_vermelhas[7]->nome,hexagonos[6][14]->x,hexagonos[6][14]->y);
    hexagonos[6][14]->unidade = unidades_vermelhas[6];
    hexagonos[14][12]->contem_unidade = 1;
    unidades_vermelhas[6]->x = hexagonos[6][14]->x;
    unidades_vermelhas[6]->y = hexagonos[14][12]->y;

           // cout<<"i: "<<i<<unidades_vermelhas[i]->tipo<<endl;

        /*unidades_vermelhas[i]->x = hexagonos[i][j]->x;
        unidades_vermelhas[i]->y =hexagonos[i][j]->y;*/
    }









