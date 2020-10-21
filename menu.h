#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <allegro.h>

volatile int fps; // VARIAVEL GLOBAL (necessária para a função install_int_ex) PARA FAZER OS FRAMES POR SEGUNDO DO JOGO PARA DESEMPENHO IGUAL COM COMPUTADORES DIFERENTES

enum pos_menu {Jogar, Instrucoes, Records, Sair, Tela_Instrucoes, Tela_Instrucoes_2};
void incrementa_timer(); // FUNÇÃO PRA FAZER O TIMER FUNCIONAR
void menu(); // FUNÇÃO PRINCIPAL DO MENU

#endif
