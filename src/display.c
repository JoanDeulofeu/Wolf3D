#include <wolf3d.h>

void	ft_display(t_s *s)
{
	ft_draw_minimap(s);
	if (s->window)
	{
		char cont = 1;
		SDL_Event event;
		while (cont != 0)
		{
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
					{
						SDL_DestroyTexture(s->wall);
						SDL_DestroyTexture(s->ground);
						SDL_DestroyTexture(s->player);
						cont = 0;
						break;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_W)
						s->posplayer.y -= 2;
					if (event.key.keysym.scancode == SDL_SCANCODE_S)
						s->posplayer.y += 2;
					if (event.key.keysym.scancode == SDL_SCANCODE_A)
						s->posplayer.x -= 2;
					if (event.key.keysym.scancode == SDL_SCANCODE_D)
						s->posplayer.x += 2;
					printf("pos_pika_x=%d, pos_pika_y=%d\nxplay=%d, yplay=%d\nhigh_play=%d, width_play=%d\n\n", s->posplayer.x, s->posplayer.y, s->xplayer, s->yplayer, s->posplayer.h, s->posplayer.w);
					ft_draw_minimap(s);
				}
			}
		}
	}
}
