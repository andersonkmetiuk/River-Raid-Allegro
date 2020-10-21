#include "jogo.h"
#include "menu.h"

void perde_vida(int *vida, int *check, float *pos_nave, float *pos_map, int *comb, int *n_com)
{
	*vida-=1; // TIRA UMA VIDA DO JOGADOR
	*pos_nave = 340; // POSIÇÃO CENTRAL DA COORDENADA X DA NAVE
	*comb = 900;
	if (*vida <= 0) // CHECA SE O JOGADOR MORREU
	{
		*vida = 3;
		*check = 0;
		allegro_message("Game Over");
	}
	else
	{
	    allegro_message("Voce perdeu uma vida! Mais cuidado.");
	}
		switch (*check) // CHECA EM QUE CHECKPOINT O JOGADOR ESTÁ. OS NÚMEROS SÃO AS COORDENADAS Y DO MAPA EM CADA CHECKPOINT
		{

			case 0:
				*pos_map = -29600;
				*n_com = 0;
				break;

			case 1:
				*pos_map = -22335;
				*n_com = 4;
				break;
					
			case 2:
				*pos_map = -12800;
				break;
					
			case 3:
				*pos_map = -6080;
				break;
				
		}
}

int max(int a, int b)
{
  if(a >= b)
   return a;
  else
   return b;
}

int min(int a, int b)
{
  if(a <= b)
   return a;
  else
   return b;
}

///METODO PIXEL PERFECT
int pixel_perfect_colision(float x1, float y1, BITMAP* carro, float x2, float y2, BITMAP* mapa) //obj1 carro obj mapa
{
   int i, j;
   int colisao = FALSE;

   //Se os retangulos estiverem se intersectando
   if(!( (x1 > x2 + mapa->w) || (y1 > y2 + mapa->h) || (x2 > x1 + carro->w) || (y2 > y1 + carro->h) ))
   {
     int cima = max(y1, y2);
	 int baixo = min(y1 + carro->h, y2 + mapa->h);
	 int esquerda = max(x1, x2);
     int direita = min(x1 + carro->w, x2 + mapa->w);

	 for(i = cima; i < baixo && !colisao; i++)
	 {
		for(j = esquerda; j < direita && !colisao; j++)
		{
		  if(getpixel(carro, j-x1, i-y1) != makecol(255,0,255) && getpixel(mapa, j-x2, i-y2) != makecol(255,0,255))
           colisao = 1;
		}
	 }

   }

   return colisao;
}



void jogo()
	{
    info_carro carro; // DECLARANDO STRUCT DO CARRO

	//BITMAPS
	BITMAP* buffer = create_bitmap(SCREEN_W,SCREEN_H);
  	carro.nave = load_bitmap("Sprites/carro.bmp",NULL);
  	BITMAP* mapa = load_bitmap("Sprites/long_map.bmp",NULL);
	BITMAP* heart = load_bitmap("Sprites/heart.bmp",NULL);
	BITMAP* tiro = load_bitmap("Sprites/tiro.bmp",NULL);
	BITMAP* fuel = load_bitmap("Sprites/fuel.bmp",NULL);
  	
  	//DECLARAÇÕES
  	carro.pos_nave = 340, carro.PNAVE = 8, carro.vida = 3;
  	float pos_map= -29600, VEL = 8, vel_tiro = 24, pos_tiroy = 485, pos_tirox, loc = -120, x_loc;
  	int check = 0, comb =900, n_com = 0;
	int exit_program = FALSE, checa_tiro = 0;
	
	fps = 0;
 	LOCK_FUNCTION(incrementa_timer);
  	LOCK_VARIABLE(fps);
  	install_int_ex(incrementa_timer, BPS_TO_TIMER(60));


	while (!exit_program)
	{
		while (fps > 0 && !exit_program)
		{
		//INPUT
 		keyboard_input();
		if (apertou(KEY_ESC))
		    {
			exit_program = TRUE;
			}
		if (apertou(KEY_P))
			{
				VEL = 0;
                allegro_message("Pausado. Aperte P pra despausar");
				int pause = FALSE;
				while (!pause && !exit_program)
				{
                    keyboard_input();
					if (apertou(KEY_P)) { pause = TRUE; }
					if (apertou(KEY_ESC))  { exit_program = TRUE; }
				}
				VEL = 8;
			}
			
		//UPDATE
		// MOVIMENTA A NAVE PROS LADOS
	if (segurou(KEY_LEFT) && carro.pos_nave > 0)
        {
		    carro.pos_nave -= carro.PNAVE;
		}
    if (segurou(KEY_RIGHT) && carro.pos_nave < 750)
        {
		    carro.pos_nave += carro.PNAVE;
		}
		// MODIFICA A VELOCIDADE DO MAPA
	if (segurou(KEY_UP))
		{
			VEL = 16;
		}
	if (segurou(KEY_DOWN))
		{
			VEL = 4;
		}
		// VOLTA PARA VELOCIDADE PADRÃO
	if (soltou(KEY_UP) || soltou(KEY_DOWN))
		{
			VEL = 8;
		}

		// CHECA SE O JOGADOR PASSOU POR ALGUM CHECKPOINT
	if (pos_map >= -22335 && check == 0)
	{
		check++;
	}
	if (pos_map >= -12800 && check == 1)
	{
		check++;
	}
	if (pos_map >= -6080 && check == 2)
	{
		check++;
	}
	
		//TIROS
	if (apertou(KEY_SPACE))
        {
			if(checa_tiro == 0) //só chama se não tem tiro na tela
			{
				checa_tiro = 1;
				pos_tirox = carro.pos_nave+14;

			}

		}

		
				//TELA
        clear_to_color(buffer,makecol(92,92,92));
		draw_sprite(buffer, mapa, 0 ,pos_map);
		draw_sprite(buffer, heart, 10, 10);
		if (carro.vida > 1)
		    draw_sprite(buffer, heart, 70, 10);
		if (carro.vida > 2)
		    draw_sprite(buffer, heart, 130, 10);
        rectfill(buffer, 10, 75, 10+(comb/5), 105, makecol(255,0,0));
		    
		if(pos_map > -27320 && n_com == 0)
		{
			x_loc = 10;
            draw_sprite(buffer, fuel, x_loc, loc);
            loc += VEL;
            if (loc > 800)
            {
            n_com = 1;
            loc = -120;
			}
		}
		if(pos_map > -26080 && n_com == 1)
		{
			x_loc = 50;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
            {
            n_com = 2;
			loc = -120;
			}
		}
		if(pos_map > -25500 && n_com == 2)
		{
			x_loc = 500;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 3;
			loc = -120;
			}
		}
		if(pos_map > -23370 && n_com == 3)
		{
			x_loc = 666;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 4;
			loc = -120;
			}
		}
		if(pos_map > -22300 && n_com == 4)
		{
			x_loc = 100;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 5;
			loc = -120;
			}
		}
		if(pos_map > -21150 && n_com == 5)
		{
			x_loc = 480;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 6;
			loc = -120;
			}
		}
		if(pos_map > -22000 && n_com == 6)
		{
			x_loc = 400;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 7;
			loc = -120;
			}
		}
		if(pos_map > -19200 && n_com == 7)
		{
			x_loc = 550;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 8;
			loc = -120;
			}
		}
		if(pos_map > -17900 && n_com == 8)
		{
			x_loc = 150;
			draw_sprite(buffer, fuel, x_loc, loc);
			loc += VEL;
			if (loc > 800)
			{
			n_com = 9;
			loc = -120;
			}
		}


		draw_sprite(buffer, carro.nave, carro.pos_nave, 500); // CARRO FICA EM CIMA DO COMBUSTIVEL, TEM QUE VIR DEPOIS
		if(checa_tiro == 1)
		{

            draw_sprite(buffer, tiro, pos_tirox , pos_tiroy);

			//atualiza o y do tiro
			pos_tiroy -= vel_tiro;
		}

		if(pos_tiroy <= 0 )
		    {
                pos_tiroy = 485;
                checa_tiro= 0;
			}



        //colisão
		if(pixel_perfect_colision(carro.pos_nave, 500, carro.nave, 0, pos_map, mapa) == 1)
		{
				//allegro_message("bateu");
		  	   	//	textout_centre_ex(buffer, font, "BATEU", 300, 100, makecol( 255, 0, 0 ), makecol( 255, 255, 255 ));
					perde_vida(&carro.vida, &check, &carro.pos_nave, &pos_map, &comb, &n_com);
		}
		if(pixel_perfect_colision(carro.pos_nave, 500, carro.nave, x_loc, loc, fuel) == 1)
		{
			comb += 4;
		}

		draw_sprite(screen, buffer , 0,0); //desenha na tela oq tem no buffer, posição x, y na origem (0,0)
        pos_map += VEL;
        comb -= 1;
        if (comb <= 0)
        {
            perde_vida(&carro.vida, &check, &carro.pos_nave, &pos_map, &comb, &n_com);
		}
        if( pos_map >= 0 )
            pos_map= -29600;
		clear(buffer);
		fps--;
}
}
		destroy_bitmap(buffer);
		destroy_bitmap(carro.nave);
		destroy_bitmap(mapa);
		destroy_bitmap(tiro);
		destroy_bitmap(fuel);
}
