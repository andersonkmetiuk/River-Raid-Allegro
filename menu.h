#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <allegro.h>

volatile int fps; // VARIAVEL GLOBAL (necess�ria para a fun��o install_int_ex) PARA FAZER OS FRAMES POR SEGUNDO DO JOGO PARA DESEMPENHO IGUAL COM COMPUTADORES DIFERENTES

enum pos_menu {Jogar, Instrucoes, Records, Sair, Tela_Instrucoes, Tela_Instrucoes_2};
void incrementa_timer(); // FUN��O PRA FAZER O TIMER FUNCIONAR
void menu(); // FUN��O PRINCIPAL DO MENU

#endif
