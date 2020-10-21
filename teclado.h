#ifndef TECLADO_H_INCLUDED
#define TECLADO_H_INCLUDED

#include <allegro.h>

int teclas_anteriores[KEY_MAX]; // VARI�VEL UTILIZADA NA FUN��O KEYBOARD_INPUT

void keyboard_input();
int apertou(int TECLA); // CHECA SE A TECLA FOI APERTADA
int segurou(int TECLA); // CHECA SE A TECLA FOI SEGURADA
int soltou(int TECLA); // CHECA SE A TECLA FOI SOLTA

#endif 
