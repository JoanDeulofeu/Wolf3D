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
# define WINDOW_WIDTH 800
# define WINDOW_HIGH 800
# define SPACE 128

typedef struct		s_map
{
	int				envi;		//environnement
	int				envi_sz;	//environnement_size
	int				roof;		//plafond
	int				roof_sz;	//plafond_size
	int				item;
}					t_map;

typedef struct		s_inv
{
	int				health;
	int				munition;
	int				gun;
	int				lives;
	int				score;
}					t_inv;

typedef struct		s_pos
{
	SDL_Rect		posplayer;
	int				xplayer;
	int				yplayer;
	int				initplayer;
	float			floatx;
	float			floaty;
	float			moovex;
	float			moovey;
	int				witem;
	float			dirplayer;
}					t_pos;

typedef struct		s_tex
{
	SDL_Texture 	*wall;
	SDL_Texture 	*ground;
	SDL_Texture 	*player;
}					t_tex;

typedef struct		s_s
{
	t_map			***map;
	t_inv			*inv;
	t_pos			*pos;
	t_tex			*tex;
	int				high;
	int				width;
	void			*render;
	void			*window;
}					t_s;

void				ft_dir_player(t_s *s, int i);
void				ft_dir_raycasting(t_s *s, int i);
int					ft_hitbox(t_s *s, int key);
int					ft_hitbox_ray(t_s *s, int key);
void				ft_check_post_pars(t_s *s);
void				ft_check(t_s *s, char *av);
void				ft_init_struct(t_s *s);
void				ft_parsing(t_s *s, char *av);
void				ft_display(t_s *s);
void				ft_usage(int usage);
void				ft_draw_minimap(t_s *s);
#endif
