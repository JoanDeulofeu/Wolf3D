#include <wolf3d.h>

void	ft_display(t_s *s)
{
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
		// SDL_Joystick* pJoy=NULL;

		SDL_JoystickEventState(SDL_DISABLE); // On indique que l'on souhaite utiliser le système d'événements pour les joysticks
		while (cont != 0)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						cont = 0;
						break;
					}
				}
			}
		}
	}
}
