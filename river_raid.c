#include <allegro.h>
#include "teclado.h"
#include "menu.h"
#include "jogo.h"

int main()
{
	allegro_init();
	install_timer();
	install_keyboard();
	set_color_depth(32); //32 bits cores
	set_gfx_mode(GFX_AUTODETECT_WINDOWED, 800 , 600, 0, 0 ); //driver de video modo janela(tem que ser maísculo), tamanho 800x600
	set_window_title ("River Raid"); //titulo da janela


	menu();



	allegro_exit();
	return 0;

}
END_OF_MAIN();
