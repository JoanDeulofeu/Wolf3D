/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tga.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgehin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:27:18 by jgehin            #+#    #+#             */
/*   Updated: 2019/03/18 11:27:21 by jgehin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void			ft_draw_tex(t_s *s, t_tga *tga)
{
	SDL_Color	clr;
	int			x;
	int			y;
	int			i;

	x = -1;
	y = 0;
	i = 0;
	SDL_SetRenderTarget(s->render, tga->texture);
	while (++x < tga->width)
	{
		while (y < tga->high)
		{
			clr.r = tga->str[i++];
			clr.b = tga->str[i++];
			clr.g = tga->str[i++];
			clr.a = tga->str[i++];
			SDL_SetRenderDrawColor(s->render, clr.g, clr.b, clr.r, clr.a);
			SDL_RenderDrawPoint(s->render, x, y);
			y++;
		}
		y = 0;
	}
	SDL_SetTextureBlendMode(tga->texture, SDL_BLENDMODE_BLEND);
	SDL_SetRenderTarget(s->render, NULL);
}

t_tga			*ft_post_tga(const char *path, t_tga *tga)
{
	tga->fd = open(path, O_RDONLY);
	if (read(tga->fd, tga->buff, 18) != 18)
		ft_usage(7);
	tga->width = tga->buff[13];
	tga->width <<= 8;
	tga->width |= tga->buff[12];
	tga->high = tga->buff[15];
	tga->high <<= 8;
	tga->high |= tga->buff[14];
	if (!(tga->str = (unsigned char *)malloc(sizeof(unsigned char) *
	tga->width * tga->high * 4)))
		ft_usage(1);
	return (tga);
}

t_tga			*ft_heart_tga(int alpha, t_tga *tga)
{
	while (++tga->u < tga->lu && tga->buff[tga->u] != '\0')
	{
		tga->str[++tga->o] = tga->buff[tga->u];
		if (alpha == 1 && (tga->o + 1) % 4 == 0)
		{
			if (tga->str[tga->o - 1] == 255 && tga->str[tga->o - 2] == 255
			&& tga->str[tga->o - 3] == 255)
				tga->str[tga->o] = 0;
		}
	}
	return (tga);
}

unsigned char	*ft_tga_to_str(const char *path, int alpha)
{
	t_tga			*tga;
	unsigned char	*tmp;

	if (!(tga = (t_tga *)malloc(sizeof(t_tga))))
		ft_usage(1);
	tga = ft_post_tga(path, tga);
	tga->i = -1;
	tga->o = -1;
	while (++tga->i < tga->width * tga->high)
	{
		ft_bzero(tga->buff, 4000);
		if (!(tga->lu = read(tga->fd, tga->buff, 4000)))
			break ;
		tga->u = -1;
		tga = ft_heart_tga(alpha, tga);
	}
	close(tga->fd);
	tmp = tga->str;
	ft_memdel((void **)&tga);
	return (tmp);
}
