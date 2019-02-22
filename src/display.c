#include <wolf3d.h>

void	ft_display(t_s *s)
{
	ft_draw_minimap(s);
	ft_rcasting(s);
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
						SDL_DestroyTexture(s->tex->wall);
						SDL_DestroyTexture(s->tex->ground);
						SDL_DestroyTexture(s->tex->player);
						cont = 0;
						break;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_W)
							ft_dir_player(s, 1);// y-
					if (event.key.keysym.scancode == SDL_SCANCODE_S)
							ft_dir_player(s, 2);// y+
					if (event.key.keysym.scancode == SDL_SCANCODE_D)
							ft_dir_player(s, 3);// x+
					if (event.key.keysym.scancode == SDL_SCANCODE_A)
							ft_dir_player(s, 4);// x-
					if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
					{
						s->pos->dirplayer += 10;
						if (s->pos->dirplayer >= 400)
							s->pos->dirplayer = 0;
					}
					if (event.key.keysym.scancode == SDL_SCANCODE_LEFT)
					{
						s->pos->dirplayer -= 10;
						if (s->pos->dirplayer < 0)
							s->pos->dirplayer = 390;
					}
					// printf("pos_pika_x=%d, pos_pika_y=%d\nxplay=%d, yplay=%d\nhigh_play=%d, width_play=%d\n\n", s->pos->posplayer.x, s->pos->posplayer.y, s->pos->xplayer, s->pos->yplayer, s->pos->posplayer.h, s->pos->posplayer.w);
					printf("pos_pika_x=%d, pos_pika_y=%d\nndirplayer=%f\nfloatx=%f\nfloaty=%f\n", s->pos->posplayer.x, s->pos->posplayer.y, s->pos->dirplayer, s->pos->floatx, s->pos->floaty);
					ft_draw_minimap(s);
					ft_rcasting(s);
				}
			}
		}
	}
}

void ft_dir_player(t_s *s, int i)
{
	int tmp;
	tmp = s->pos->dirplayer;
	if (i == 2)
	{
		if (s->pos->dirplayer < 200)
			s->pos->dirplayer += 200;
		else
			s->pos->dirplayer -= 200;
	}
	if (i == 4)
	{
		if (s->pos->dirplayer < 100)
			s->pos->dirplayer += 300;
		else
			s->pos->dirplayer -= 100;
	}
	if (i == 3)
	{
		if (s->pos->dirplayer > 300)
			s->pos->dirplayer -= 100;
		else
			s->pos->dirplayer += 100;
	}
	if (s->pos->dirplayer <= 100)
	{
		if(ft_hitbox(s,1))
		{
		s->pos->floaty -= (1-(s->pos->dirplayer/100));
		if (s->pos->floaty < s->pos->posplayer.y - 0.5)
			s->pos->posplayer.y --;
		}
		if(ft_hitbox(s,3))
		{
		s->pos->floatx += (s->pos->dirplayer/100);
		if (s->pos->floatx > s->pos->posplayer.x + 0.5)
			s->pos->posplayer.x ++;
		}
	}
	if (s->pos->dirplayer > 100 && s->pos->dirplayer <= 200)
	{
		if(ft_hitbox(s,2))
		{
		s->pos->floaty += ((s->pos->dirplayer-100)/100);
		if (s->pos->floaty > s->pos->posplayer.y + 0.5 )
			s->pos->posplayer.y ++;
		}
		if(ft_hitbox(s,3))
		{
		s->pos->floatx += (1-((s->pos->dirplayer-100)/100));
		if (s->pos->floatx > s->pos->posplayer.x + 0.5 )
			s->pos->posplayer.x ++;
		}
	}
	if (s->pos->dirplayer > 200 && s->pos->dirplayer <= 300)
	{
		if(ft_hitbox(s,2))
		{
		s->pos->floaty += (1-((s->pos->dirplayer-200)/100));
		if (s->pos->floaty > s->pos->posplayer.y + 0.5 )
			s->pos->posplayer.y ++;
		}
		if(ft_hitbox(s,4))
		{
		s->pos->floatx -= ((s->pos->dirplayer-200)/100);
		if (s->pos->floatx < s->pos->posplayer.x - 0.5 )
			s->pos->posplayer.x --;
		}
	}
	if (s->pos->dirplayer > 300 && s->pos->dirplayer <= 400)
	{
		if(ft_hitbox(s,1))
		{
		s->pos->floaty -= ((s->pos->dirplayer-300)/100);
		if (s->pos->floaty < s->pos->posplayer.y - 0.5 )
			s->pos->posplayer.y --;
		}
		if(ft_hitbox(s,4))
		{
		s->pos->floatx -= (1-((s->pos->dirplayer-300)/100));
		if (s->pos->floatx < s->pos->posplayer.x - 0.5)
			s->pos->posplayer.x --;
		}
	}
	s->pos->dirplayer = tmp;
	s->pos->xplayer = s->pos->posplayer.x + SPACE / 8;
	s->pos->yplayer = s->pos->posplayer.y + SPACE / 8;
}

void ft_dir_raycasting(t_s *s, int i)
{
	int tmp;
	tmp = s->pos->dirplayer;
	s->pos->moovex = s->pos->floatx + SPACE / 8;
	s->pos->moovey = s->pos->floaty + SPACE / 8;
	if (i == 2)
	{
		if (s->pos->dirplayer < 200)
			s->pos->dirplayer += 200;
		else
			s->pos->dirplayer -= 200;
	}
	if (i == 4)
	{
		if (s->pos->dirplayer < 100)
			s->pos->dirplayer += 300;
		else
			s->pos->dirplayer -= 100;
	}
	if (i == 3)
	{
		if (s->pos->dirplayer > 300)
			s->pos->dirplayer -= 100;
		else
			s->pos->dirplayer += 100;
	}
	if (s->pos->dirplayer <= 100)
	{
		while(ft_hitbox_ray(s,1) && ft_hitbox_ray(s,3))
		{
			s->pos->moovey -= (1-(s->pos->dirplayer/100));
			s->pos->moovex += (s->pos->dirplayer/100);
		}
	}
	if (s->pos->dirplayer > 100 && s->pos->dirplayer <= 200)
	{
		while(ft_hitbox_ray(s,2) && ft_hitbox_ray(s,3))
		{
			s->pos->moovey += ((s->pos->dirplayer-100)/100);
			s->pos->moovex += (1-((s->pos->dirplayer-100)/100));
		}
	}
	if (s->pos->dirplayer > 200 && s->pos->dirplayer <= 300)
	{
		while(ft_hitbox_ray(s,2) && ft_hitbox_ray(s,4))
		{
			s->pos->moovey += (1-((s->pos->dirplayer-200)/100));
			s->pos->moovex -= ((s->pos->dirplayer-200)/100);
		}
	}
	if (s->pos->dirplayer > 300 && s->pos->dirplayer <= 400)
	{
		while(ft_hitbox_ray(s,1) && ft_hitbox_ray(s,4))
		{
			s->pos->moovey -= ((s->pos->dirplayer-300)/100);
			s->pos->moovex -= (1-((s->pos->dirplayer-300)/100));
		}
	}
	s->pos->dirplayer = tmp;
}
