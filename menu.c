#include "menu.h"


void incrementa_timer() { fps++; }
END_OF_FUNCTION(incrementa_timer)

void menu()	
{

	//BITMAPS: INICIALIZA OS BITMAPS UTILIZADOS NO MENU
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
  	BITMAP* menu1 = load_bitmap("Sprites/menu1.bmp",NULL);
  	BITMAP* menu2 = load_bitmap("Sprites/menu2.bmp",NULL);
  	BITMAP* menu3 = load_bitmap("Sprites/menu3.bmp",NULL);
  	BITMAP* menu4 = load_bitmap("Sprites/menu4.bmp",NULL);
  	BITMAP* instrucoes = load_bitmap("Sprites/instrucoes_novo.bmp",NULL);
  	BITMAP* instrucoes_2 = load_bitmap("Sprites/instrucoes_novo2.bmp",NULL);



	int pos_menu=0; // VARIÁVEL PARA DETERMINAR EM QUE OPÇÃO O USUÁRIO ESTÁ
	int exit_program = FALSE; // VARIÁVEL PARA DETERMINAR A SAÍDA DO PROGRAMA
	int game = FALSE; // VARIÁVEL PARA DETERMINAR SE O JOGADOR VAI ENTRAR NO JOGO. CASO SEJA FALSA, AO SAIR DO LOOP O USUÁRIO SAI DO PROGRAMA
	fps = 0;
 	LOCK_FUNCTION(incrementa_timer);
  	LOCK_VARIABLE(fps);
  	install_int_ex(incrementa_timer, BPS_TO_TIMER(60)); // BPS SIGNIFICA BATIDAS POR SEGUNDO, OU SEJA, O NOSSO TIMER TEM 60 FRAMES POR SEGUNDO

	while(!exit_program && !game) // É NECESSÁRIO ESTE WHILE PARA QUANDO SAIR DO LOOP DE FPS, NÃO SAIR DO LOOP DO MENU
	{
		while (fps>0 && !exit_program && !game) // O EXIT_PROGRAM E O GAME SÃO AS DUAS CONDIÇÕES PRA SAIR DO LOOP. OS MOTIVOS DE QUERER SAIR DO LOOP MENU SÃO FECHAR O PROGRAMA E INICIALIZAR O JOGO
		{
		//INPUT

	    keyboard_input();
		if (apertou(KEY_ESC))
		    {
			exit_program = TRUE;
			}

		//UPDATE
		switch(pos_menu)
		{

			case Jogar:

            draw_sprite(buffer, menu1, 0, 0);
            if (apertou(KEY_ENTER))
			{
				game = TRUE;
			}
			break;



			case Instrucoes:

            draw_sprite(buffer, menu2, 0, 0);
            if (apertou(KEY_ENTER))
			{
				pos_menu = Tela_Instrucoes;
			}
			break;



			case Records:

            draw_sprite(buffer, menu3, 0, 0);
			break;



			case Sair:

            draw_sprite(buffer, menu4, 0, 0);
            if (apertou(KEY_ENTER))
			{
				exit_program = TRUE;
			}
			break;



			case Tela_Instrucoes:

			draw_sprite(buffer, instrucoes, 0,  0);
			if (apertou(KEY_BACKSPACE))
			{
				pos_menu = Instrucoes;
			}
			if (apertou(KEY_RIGHT))
 			{
				pos_menu = Tela_Instrucoes_2;
			}
			break;
			
			case Tela_Instrucoes_2:

			draw_sprite(buffer, instrucoes_2, 0, 0);
			if (apertou(KEY_BACKSPACE))
			{
				pos_menu = 1;
			}
			if (apertou(KEY_LEFT))
			{
				pos_menu = Tela_Instrucoes;
			}

		}


	 if (apertou(KEY_UP))
        {
		    if(pos_menu>0 && pos_menu<=3)
            pos_menu--;
		}
	if (apertou(KEY_DOWN))
        {
			if(pos_menu<3 && pos_menu >=0)
			   pos_menu++;
		}


		//TELA
		draw_sprite(screen, buffer , 0,0); //desenha na tela oq tem no buffer, posição x, y na origem (0,0)
		clear(buffer);
		fps--;

}
}

destroy_bitmap(buffer);
destroy_bitmap(menu1);
destroy_bitmap(menu2);
destroy_bitmap(menu3);
destroy_bitmap(menu4);
destroy_bitmap(instrucoes);
destroy_bitmap(instrucoes_2);
	if (game)
	    jogo(fps);
}
END_OF_FUNCTION(menu)
