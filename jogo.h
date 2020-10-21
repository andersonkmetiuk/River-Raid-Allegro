#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <allegro.h>

void jogo(); // FUN��O PRINCIPAL DO JOGO
int max(int a, int b);
int min(int a, int b);
int pixel_perfect_colision(float x1,float y1, BITMAP* carro, float x2, float y2, BITMAP* mapa); // CHECA COLIS�O, RETORNANDO O VALOR 1 SE HOUVER E 0 SE N�O HOUVER
void perde_vida(int *vida, int *check, float *pos_nave, float *pos_map, int *comb, int *n_com); // QUANDO A FUN��O � CHAMADA, DIMINUI UMA VIDA E VOLTA PRO ULTIMO CHECKPOINT

typedef struct
{
	float pos_nave; // POSI��O X DA NAVE
	float PNAVE; // VELOCIDADE HORIZONTAL DA NAVE
	BITMAP* nave; // IMAGEM DA NAVE
	int vida; // NUMERO DE VIDAS
}info_carro;

#endif
