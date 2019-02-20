#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL2/SDL.h>
//# include "SDL_mixer.h"
# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# define WINDOW_WIDTH 600
# define WINDOW_HIGH 400

typedef struct		s_map
{
	int				envi;		//environnement
	int				envi_sz;	//environnement_size
	int				roof;		//plafond
	int				roof_sz;	//plafond_size
	int				item;
}					t_map;

typedef struct		s_s
{
	t_map			***map;
	int				high;
	int				width;
	void			*render;
	void			*window;
	SDL_Texture 	*wall;
	SDL_Texture 	*ground;
}					t_s;
void	ft_check_post_pars(t_s *s);
void	ft_check(t_s *s, char *av);
void	ft_init_struct(t_s *s);
void	ft_parsing(t_s *s, char *av);
void	ft_display(t_s *s);
void	ft_usage(int usage);
void	ft_draw_minimap(t_s *s);
#endif
