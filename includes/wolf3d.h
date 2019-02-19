#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL2/SDL.h>
//# include "SDL_mixer.h"
# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

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
	t_map			**map;
	int				high;
	int				width;
}					t_s;
void	ft_check(t_s *s, char *av);
void	ft_init_struct(t_s *s);
void	ft_parsing(t_s *s, char *av);
#endif
