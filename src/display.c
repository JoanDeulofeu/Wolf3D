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
						if (ft_hitbox(s, SDL_SCANCODE_W))
							ft_dir_player(s, 1);// y-
					if (event.key.keysym.scancode == SDL_SCANCODE_S)
						if (ft_hitbox(s, SDL_SCANCODE_S))
							ft_dir_player(s, 2);// y+
					if (event.key.keysym.scancode == SDL_SCANCODE_D)
						if (ft_hitbox(s, SDL_SCANCODE_D))
							ft_dir_player(s, 3);// x+
					if (event.key.keysym.scancode == SDL_SCANCODE_A)
						if (ft_hitbox(s, SDL_SCANCODE_A))
							ft_dir_player(s, 4);// x-
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						s->dirplayer += 10;
						if (s->dirplayer >= 400)
							s->dirplayer = 0;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						s->dirplayer -= 10;
						if (s->dirplayer < 0)
							s->dirplayer = 390;
					}
					// printf("pos_pika_x=%d, pos_pika_y=%d\nxplay=%d, yplay=%d\nhigh_play=%d, width_play=%d\n\n", s->posplayer.x, s->posplayer.y, s->xplayer, s->yplayer, s->posplayer.h, s->posplayer.w);
					printf("pos_pika_x=%d, pos_pika_y=%d\nxplay=%d \ndirplayer=%f\nfloatx=%f\nfloaty=%f\n", s->posplayer.x, s->posplayer.y, s->xplayer, s->dirplayer, s->floatx, s->floaty);
					ft_draw_minimap(s);
				}
			}
		}
	}
}

void ft_dir_player(t_s *s, int i)
{
	int tmp;
	tmp = s->dirplayer;
	if (i == 2)
	{
		if (s->dirplayer < 200)
			s->dirplayer += 200;
		else
			s->dirplayer -= 200;
	}
	if (i == 4)
	{
		if (s->dirplayer < 100)
			s->dirplayer += 300;
		else
			s->dirplayer -= 100;
	}
	if (i == 3)
	{
		if (s->dirplayer > 300)
			s->dirplayer -= 100;
		else
			s->dirplayer += 100;
	}
	if (s->dirplayer <= 100)
	{
		s->floaty -= (1-(s->dirplayer/100));
		if (s->floaty < s->posplayer.y - 0.5)
			s->posplayer.y --;
		s->floatx += (s->dirplayer/100);
		if (s->floatx > s->posplayer.x + 0.5)
			s->posplayer.x ++;
	}
	if (s->dirplayer > 100 && s->dirplayer <= 200)
	{
		s->floaty += ((s->dirplayer-100)/100);
		if (s->floaty > s->posplayer.y + 0.5)
			s->posplayer.y ++;
		s->floatx += (1-((s->dirplayer-100)/100));
		if (s->floatx > s->posplayer.x + 0.5)
			s->posplayer.x ++;
	}
	if (s->dirplayer > 200 && s->dirplayer <= 300)
	{
		s->floaty += (1-((s->dirplayer-200)/100));
		if (s->floaty > s->posplayer.y + 0.5)
			s->posplayer.y ++;
		s->floatx -= ((s->dirplayer-200)/100);
		if (s->floatx < s->posplayer.x - 0.5)
			s->posplayer.x --;
	}
	if (s->dirplayer > 300 && s->dirplayer <= 400)
	{
		s->floaty -= ((s->dirplayer-300)/100);
		if (s->floaty < s->posplayer.y - 0.5)
			s->posplayer.y --;
		s->floatx -= (1-((s->dirplayer-300)/100));
		if (s->floatx < s->posplayer.x - 0.5)
			s->posplayer.x --;
	}
	s->dirplayer = tmp;
}
