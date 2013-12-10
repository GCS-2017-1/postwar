#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <stdlib.h>
#include <cstdio>
#include <string.h>
#include "../../../../include/draw.h"
#include "../../../../include/video.h"
#include "../../../../include/loop.h"
#include "../../../../include/gamefeatures.h"

using namespace std;

void carrega_franca(SDL_Surface *screen,string lado){

    string lado1("servidor");
    string cor = "vermelho";

    for(int i=0, j=1;i<6;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho.png";
        SDL_Surface *soldado1 = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque.png";
        SDL_Surface *ataque_soldado = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_baixo.png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_vermelho_ataque_cima.png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/soldado_lateral_vermelho.png";
        SDL_Surface *soldado_lateral_a= load_Image(caminho, screen);
        Unidade *soldado = new Unidade();

        string unidadea1 = "soldado";
        setar_soldado(soldado, cor, unidadea1, soldado1, ataque_soldado, ataque_baixo, ataque_cima,soldado_lateral_a, id);
        id++;
        unidades_azul.push_back(soldado);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;

        if(i==0){
            hexagonos[7][12]->unidade = soldado;
            hexagonos[7][12]->contem_unidade = 1;
            dst.x = hexagonos[7][12]->x;
            dst.y = hexagonos[7][12]->y;
            SDL_BlitSurface(soldado->nome, &cutBox, screen, &dst);
        }
        caminho = "source/GameFeatures/Jogar/Fase1/images/bryjstudios_cabana_vermelha.png";
        SDL_Surface *quartel_azul_cabana = load_Image(caminho, screen);
        Unidade *quartel_a = new Unidade();
        string quarte = "quartel";
        setar_quartel(quartel_a,cor,quarte,quartel_azul_cabana, quartel_azul_cabana, quartel_azul_cabana, id);
        id++;
        BlitImage(screen,quartel_azul_cabana,hexagonos[6][1]->x,hexagonos[6][1]->y);
        hexagonos[5][1]->unidade = quartel_a;
        hexagonos[5][1]->contem_unidade = 1;
        hexagonos[6][1]->unidade = quartel_a;
        hexagonos[6][1]->contem_unidade = 1;
        hexagonos[6][2]->contem_unidade = 1;
        hexagonos[6][2]->unidade = quartel_a;
        hexagonos[7][1]->contem_unidade = 1;
        hexagonos[7][1]->unidade = quartel_a;
        hexagonos[8][1]->contem_unidade = 1;
        hexagonos[8][1]->unidade = quartel_a;
        hexagonos[8][2]->contem_unidade = 1;
        hexagonos[8][2]->unidade = quartel_a;
        hexagonos[9][1]->contem_unidade = 1;
        hexagonos[9][1]->unidade = quartel_a;

    }

    for(int i=6, j=1;i<8;i++,j+=30){

        string caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_vermelho.png";
        SDL_Surface *tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_vermelho.png";
        SDL_Surface *ataque_tanque = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_ataqueParaBaixo(vermelho).png";
        SDL_Surface *ataque_baixo = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_ataqueParaCima(vermelho).png";
        SDL_Surface *ataque_cima = load_Image(caminho, screen);
        caminho = "source/GameFeatures/Jogar/Fase1/images/tanque_lateral_vermelho.png";
        SDL_Surface *tanque_lateral= load_Image(caminho, screen);
        Unidade *tanque1 = new Unidade();

        string unidadea1 = "tanque";
        setar_tanque(tanque1, cor, unidadea1, tanque, ataque_tanque, ataque_baixo, ataque_cima,tanque_lateral, id);
        id++;
        unidades_azul.push_back(tanque1);
        //if(i+2<=hexagonos.size()){
        SDL_Rect dst;
        dst.x = hexagonos[i*2][3]->x;
        dst.y = hexagonos[i*2][3]->y;
        dst.h = 0;
        dst.w = 0;
        SDL_BlitSurface(unidades_azul[i]->nome, &cutBox,  screen, &dst);
        hexagonos[i*2][3]->unidade = unidades_azul[i];
        hexagonos[i*2][3]->contem_unidade = 1;
    }

    string caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_esquerda1.png";
    SDL_Surface *metralhadora1 = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/metralhadora_vermelha_ataque.png";
    SDL_Surface *metralhadora_ataque = load_Image(caminho, screen);
    caminho = "source/GameFeatures/Jogar/Fase1/images/barraLateral_vermelho.png";
    SDL_Surface *metralhadora_lateral = load_Image(caminho, screen);
    Unidade *metralhadora = new Unidade();
    string unidadea2 = "metralhadora";
    setar_metralhadora(metralhadora, cor, unidadea2, metralhadora1, metralhadora_ataque, metralhadora_lateral, id);
    id++;
    unidades_azul.push_back(metralhadora);

    BlitImage(screen,unidades_azul[10]->nome,hexagonos[6][4]->x,hexagonos[6][4]->y);

    hexagonos[6][4]->contem_unidade=1;
    hexagonos[6][4]->unidade = metralhadora;
    hexagonos[7][4]->contem_unidade=1;
    hexagonos[7][4]->unidade = metralhadora;
    hexagonos[8][4]->contem_unidade=1;
    hexagonos[8][4]->unidade = metralhadora;




    SDL_Color blue;
	blue.g = blue.b = 0;
	blue.r = 255;
	SDL_Color white;
	white.r = white.g = white.b = 255;

	//drawCircle(screen, 20, 44, 137, blue);
	//drawCircle(screen, 20, 78, 157, blue);
}






