#include <wolf3d.h>

int main(int ac, char** av)
{
	(void)ac;
	(void)av;
	SDL_Window *pWindow = NULL;

	/* Initialisation*/
	if (SDL_Init(SDL_INIT_VIDEO) != 0 )
	{
		fprintf(stdout,"Échec de l'initialisation de la SDL (%s)\n",SDL_GetError());
		return -1;
	}

	/* Création de la fenêtre */
	pWindow = SDL_CreateWindow("Ma première application SDL2",100, 100, 640, 480, SDL_WINDOW_FULLSCREEN_DESKTOP);

	if( pWindow )
	{
		SDL_Delay(3000); /* Attendre trois secondes, que l'utilisateur voit la fenêtre */

		SDL_DestroyWindow(pWindow);
	}
	else
	{
		fprintf(stderr,"Erreur de création de la fenêtre:%s\n",SDL_GetError());
	}
	SDL_Quit();
	return 0;
}

	/*-----------------------------------------*/

// int main( int ac, char **av)
// {
// 	(void)ac;
// 	(void)av;
//     SDL_Surface *screen;
//
//     if( SDL_Init( SDL_INIT_VIDEO ) == -1 )
//     {
//         printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
//         return EXIT_FAILURE;
//     }
//
//     atexit( SDL_Quit );
//     screen = SDL_SetVideoMode( 640, 480, 16, SDL_WINDOW_SHOWN);
//
//     if( screen == NULL )
//     {
//         printf( "Can't set video mode: %s\n", SDL_GetError( ) );
//         return EXIT_FAILURE;
//     }
//
//     SDL_Delay( 3000 );
//
//     return EXIT_SUCCESS;
// }
