#include <wolf3d.h>

// void ft_parsing_to_trace(t_s *s)
// {
// 	int x;
// 	x = 0
// 	while(x <= s->high)
// 	{
// 		if (s->envi<1000)
// 			SDL_SetRenderDrawColor(s->render, 255, 0, 0, 255);
// 		if (s->envi>1000)
// 		SDL_RenderDrawPoint(s->render, x, y);
// 		x++;
// 	}
// }
int	ft_testevent(t_s *s)
{
	// SDL_Event event;


	int i;
	SDL_SetRenderDrawColor(s->render, 255, 0, 0, 255);
	for (i = 0; i < WINDOW_WIDTH; ++i)
		SDL_RenderDrawPoint(s->render, i, i);
	// ft_parsing_to_trace(s);
	SDL_RenderPresent(s->render);
	if (s->window)
	{
		char cont = 1; /* Détermine si on continue la boucle principale */
		SDL_Event event;
		SDL_Joystick* pJoy=NULL;

		SDL_JoystickEventState(SDL_ENABLE); // On indique que l'on souhaite utiliser le système d'événements pour les joysticks

		while ( cont != 0 )
		{
			while ( SDL_PollEvent(&event) )
			{
				/* Traitement de l'événement */
				switch (event.type) /* Quel événement avons-nous ? */
				{
					case SDL_KEYDOWN:
						fprintf(stdout, "Un appuie sur une touche :\n");
						fprintf(stdout, "\trépétition ? : %d\n",event.key.repeat);
						fprintf(stdout, "\tscancode : %d\n",event.key.keysym.scancode);
						fprintf(stdout, "\tkey : %d\n",event.key.keysym.sym);
						if ( event.key.keysym.scancode == SDL_SCANCODE_ESCAPE )
						{
							cont = 0;
						}
						break;
					case SDL_KEYUP:
						fprintf(stdout, "Un relachement d'une touche :\n");
						fprintf(stdout, "\trépétition ? : %d\n",event.key.repeat);
						fprintf(stdout, "\tscancode : %d\n",event.key.keysym.scancode);
						fprintf(stdout, "\tkey : %d\n",event.key.keysym.sym);
						break;

					case SDL_MOUSEMOTION:
						fprintf(stdout, "Un déplacement de la souris :\n");
						fprintf(stdout, "\tfenêtre : %d\n",event.motion.windowID);
						fprintf(stdout, "\tsouris : %d\n",event.motion.which);
						fprintf(stdout, "\tposition : %d;%d\n",event.motion.x,event.motion.y);
						fprintf(stdout, "\tdelta : %d;%d\n",event.motion.xrel,event.motion.yrel);
						break;
					case SDL_MOUSEBUTTONUP:
						fprintf(stdout, "Un relachement d'un bouton de la souris :\n");
						fprintf(stdout, "\tfenêtre : %d\n",event.button.windowID);
						fprintf(stdout, "\tsouris : %d\n",event.button.which);
						fprintf(stdout, "\tbouton : %d\n",event.button.button);
#if SDL_VERSION_ATLEAST(2,0,2)
						fprintf(stdout, "\tclics : %d\n",event.button.clicks);
#endif
						fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
						break;
					case SDL_MOUSEBUTTONDOWN:
						fprintf(stdout, "Un appuie sur un bouton de la souris :\n");
						fprintf(stdout, "\tfenêtre : %d\n",event.button.windowID);
						fprintf(stdout, "\tsouris : %d\n",event.button.which);
						fprintf(stdout, "\tbouton : %d\n",event.button.button);
#if SDL_VERSION_ATLEAST(2,0,2)
						fprintf(stdout, "\tclics : %d\n",event.button.clicks);
#endif
						fprintf(stdout, "\tposition : %d;%d\n",event.button.x,event.button.y);
						break;
					case SDL_MOUSEWHEEL:
						fprintf(stdout, "Roulette de la souris :\n");
						fprintf(stdout, "\tfenêtre : %d\n",event.wheel.windowID);
						fprintf(stdout, "\tsouris : %d\n",event.wheel.which);
						fprintf(stdout, "\tposition : %d;%d\n",event.wheel.x,event.wheel.y);
						break;
					case SDL_JOYDEVICEADDED:
						fprintf(stdout, "Connexion de joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jdevice.which);
						if ( pJoy == NULL )
						{
							pJoy = SDL_JoystickOpen(event.jdevice.which);
						}
						else
						{
							fprintf(stdout,"Ce nouveau joystick ne sera pas ouvert (le programme ne gère qu'un joystick)\n");
						}
						break;
					case SDL_JOYDEVICEREMOVED:
						fprintf(stdout, "Déconnexion de joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jdevice.which);

						if ( pJoy != NULL )
						{
							SDL_JoystickClose(pJoy);
							pJoy = NULL;
						}
						break;
					case SDL_JOYAXISMOTION:
						fprintf(stdout, "Déplacement joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jaxis.which);
						fprintf(stdout, "\taxe : %d\n",event.jaxis.axis);
						fprintf(stdout, "\tvaleur : %d\n",event.jaxis.value);
						break;
					case SDL_JOYBUTTONDOWN:
						fprintf(stdout, "Appui bouton joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jbutton.which);
						fprintf(stdout, "\tbutton : %d\n",event.jbutton.button);
						fprintf(stdout, "\tétat : %d\n",event.jbutton.state);
						break;
					case SDL_JOYBUTTONUP:
						fprintf(stdout, "Relâchement bouton joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jbutton.which);
						fprintf(stdout, "\tbutton : %d\n",event.jbutton.button);
						fprintf(stdout, "\tétat : %d\n",event.jbutton.state);
						break;
					case SDL_JOYBALLMOTION:
						fprintf(stdout, "Déplacement de trackball :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jball.which);
						fprintf(stdout, "\ttrackball : %d\n",event.jball.ball);
						fprintf(stdout, "\tdéplacement : %d;%d\n",event.jball.xrel,event.jball.yrel);
						break;
					case SDL_JOYHATMOTION:
						fprintf(stdout, "Déplacement de chapeau d'un joystick :\n");
						fprintf(stdout, "\tjoystick : %d\n",event.jhat.which);
						fprintf(stdout, "\tbutton : %d\n",event.jhat.hat);
						fprintf(stdout, "\tvaleur : %d\n",event.jhat.value);
						break;
					case SDL_WINDOWEVENT:
						fprintf(stdout, "Un événement de fenêtre, sur la fenêtre : %d\n",event.window.windowID);
						// En théorie, ici, il faudrait faire un autre test ou switch pour chaque type de cet événement
						break;
					default:
						fprintf(stdout, "Événement non traité : %d\n",event.type);
				}
				fprintf(stdout, "\n");
			}
			/* On a traité les événements, on peut continuer le jeu */
		}
		if ( pJoy != NULL )
		{
			SDL_JoystickClose(pJoy);
			pJoy = NULL;
		}
		SDL_DestroyWindow(s->window);
	}
	else
	{
		fprintf(stderr,"Erreur de création de la fenêtre: %s\n",SDL_GetError());
	}
	SDL_DestroyRenderer(s->render);
	SDL_DestroyWindow(s->window);
	SDL_Quit();
	return EXIT_SUCCESS;
}