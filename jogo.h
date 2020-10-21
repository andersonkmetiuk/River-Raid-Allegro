#ifndef JOGO_H_INCLUDED
#define JOGO_H_INCLUDED

#include <allegro.h>

void jogo(); // FUNÇÃO PRINCIPAL DO JOGO
int max(int a, int b);
int min(int a, int b);
int pixel_perfect_colision(float x1,float y1, BITMAP* carro, float x2, float y2, BITMAP* mapa); // CHECA COLISÃO, RETORNANDO O VALOR 1 SE HOUVER E 0 SE NÃO HOUVER
void perde_vida(int *vida, int *check, float *pos_nave, float *pos_map, int *comb, int *n_com); // QUANDO A FUNÇÃO É CHAMADA, DIMINUI UMA VIDA E VOLTA PRO ULTIMO CHECKPOINT

typedef struct
{
	float pos_nave; // POSIÇÃO X DA NAVE
	float PNAVE; // VELOCIDADE HORIZONTAL DA NAVE
	BITMAP* nave; // IMAGEM DA NAVE
	int vida; // NUMERO DE VIDAS
}info_carro;

#endif
