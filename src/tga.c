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
	SDL_SetTextureBlendMode(tga->texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(s->render, NULL);
}

// SDL_Texture		*ft_tga(t_s *s, const char *path, int alpha)
// {
// 	t_tga			*tga;
// 	int				lu;
// 	int				i;
// 	int				u;
// 	int				o;
//
// 	if (!(tga = (t_tga *)malloc(sizeof(t_tga))))
// 		ft_usage(1);
// 	i = -1;
// 	tga->fd = open(path, O_RDONLY);
// 	if (read(tga->fd, tga->buff, 18) != 18)
// 		ft_usage(7);
// 	tga->width = tga->buff[13];
// 	tga->width <<= 8;
// 	tga->width |= tga->buff[12];
// 	tga->high = tga->buff[15];
// 	tga->high <<= 8;
// 	tga->high |= tga->buff[14];
// 	tga->texture = SDL_CreateTexture(s->render, SDL_PIXELFORMAT_RGBA32, SDL_TEXTUREACCESS_TARGET, tga->width, tga->high);
// 	i = -1;
// 	if (!(tga->str = (unsigned char *)malloc(sizeof(unsigned char) * tga->width * tga->high * 4)))
// 		ft_usage(1);
// 	o = 0;
// 	while (++i < tga->width * tga->high)
// 	{
// 		ft_bzero(tga->buff, 4000);
// 		if (!(lu = read(tga->fd, tga->buff, 4000)))
// 			break;
// 		u = 0;
// 		while (u < lu && tga->buff[u] != '\0')
// 		{
// 			tga->str[o] = tga->buff[u];
// 			if (alpha == 1 && (o + 1) % 4 == 0)
// 			{
// 				if (tga->str[o - 1] == 255 && tga->str[o - 2] == 255 && tga->str[o - 3] == 255)
// 					tga->str[o] = 0;
// 			}
// 			u++;
// 			o++;
// 		}
// 	}
// 	close(tga->fd);
// 	ft_draw_tex(s, tga);
// 	return (tga->texture);
// }

unsigned char	*ft_tga_to_str(const char *path, int alpha)
{
	t_tga			*tga;
	int				lu;
	int				i;
	int				u;
	int				o;
	unsigned char	*tmp;

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
			if (alpha == 1 && (o + 1) % 4 == 0)
			{
				if (tga->str[o - 1] == 255 && tga->str[o - 2] == 255 && tga->str[o - 3] == 255)
					tga->str[o] = 0;
			}
			u++;
			o++;
		}
	}
	close(tga->fd);
	tmp = tga->str;
	ft_memdel((void **)&tga);
	return (tmp);
}
