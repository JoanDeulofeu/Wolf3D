#include "wolf3d.h"

void			ft_draw_tex(t_s *s, t_tga *tga)
{
	int		r;
	int		g;
	int		b;
	int		a;
	int		x;
	int		y;
	int		i;

	x = 0;
	y = 0;
	i = 0;
	SDL_SetRenderTarget(s->render, tga->texture);
	while (x < tga->width)
	{
		while (y < tga->high)
		{
			r = tga->str[i++];
			b = tga->str[i++];
			g = tga->str[i++];
			a = tga->str[i++];
			SDL_SetRenderDrawColor(s->render, g, b, r, a);
			SDL_RenderDrawPoint(s->render, x, y);
			y++;
		}
		y = 0;
		x++;
	}
	SDL_SetRenderTarget(s->render, NULL);
}

SDL_Texture		*ft_tga(t_s *s, const char *path)
{
	t_tga			*tga;
	int				lu;
	int				i;
	int				u;
	int				o;

	if (!(tga = (t_tga *)malloc(sizeof(t_tga))))
		ft_usage(1);
	i = -1;
	tga->fd = open(path, O_RDONLY);
	if (read(tga->fd, tga->buff, 18) != 18)
		ft_usage(7);
	tga->width = tga->buff[13];
	tga->width <<= 8;
	tga->width |= tga->buff[12];
	tga->high = tga->buff[15];
	tga->high <<= 8;
	tga->high |= tga->buff[14];
	tga->texture = NULL; //inutile
	tga->texture = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, tga->width, tga->high);
	i = -1;
	if (!(tga->str = (unsigned char *)malloc(sizeof(unsigned char) * tga->width * tga->high * 4)))
		ft_usage(1);
	o = 0;
	while (++i < tga->width * tga->high)
	{
		ft_bzero(tga->buff, 4000);
		if (!(lu = read(tga->fd, tga->buff, 4000)))
			break;
		u = 0;
		while (u < lu && tga->buff[u] != '\0')
		{
			tga->str[o] = tga->buff[u];
			// if (o > 39000 && o < 40000)
			// {
				// printf("b[%d] = %d  ", u , tga->buff[u]);
				// if ((u + 1) % 8 == 0)
				// 	printf("\n");
			// }
			u++;
			o++;
		}
		while (++u < 128)
			printf("str[%d] = %d\n", u-64, tga->buff[u-64]);
		// printf("o = %d\n", o);
		// ft_putstr("\n-------\n");
	}
	u = -1;
	printf("=-=-= high=%d, width=%d =-=-=\n",tga->high,tga->width);

	close(tga->fd);
	ft_draw_tex(s, tga);
	return (tga->texture);
}
