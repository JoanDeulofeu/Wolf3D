#ifndef WOLF3D_H
# define WOLF3D_H
# include <SDL2/SDL.h>
// # include <SDL2/SDL_image.h>
//# include "SDL_mixer.h"
# include "libft.h"
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# define WINDOW_WIDTH 800
# define WINDOW_HIGH 800
# define SPACE 16
# define SPEED 2

typedef struct		s_tga
{
	int				fd;
	int				width;
	int				high;
	unsigned char	buff[4000];
	unsigned char	*str;
	SDL_Texture 	*texture;
}					t_tga;

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
	int				initplayer;
	float			floatx;
	float			floaty;
	float			moovex;
	float			moovey;
	int				witem;
	float			dirplayer;
	int				nsew;
	int				doorx;
	int				doory;
	int				door;
	int				eyehigh;
	int				tp;
}					t_pos;

typedef struct		s_tex
{
	SDL_Texture		*wall;
	unsigned char	*wall1;
	unsigned char	*wall2;
	unsigned char	*wall3;
	unsigned char	*wall4;
	unsigned char	*wall5;
	SDL_Texture 	*ground;
	SDL_Texture 	*player;
	SDL_Texture 	*screen;
	SDL_Texture 	*door;
	SDL_Texture 	*portal;
}					t_tex;

typedef struct		s_ray
{
	int				texorcolor;
	float			diffx;
	float			diffy;
	float			savex;
	float			savey;
	float			inty;
	float			intx;
	float			inty2;
	float			intx2;
	float			save1;
	float			save2;
}					t_ray;

typedef struct		s_s
{
	t_map			***map;
	t_inv			*inv;
	t_pos			*pos;
	t_tex			*tex;
	t_ray			*ray;
	int				high;
	int				width;
	int				speed;
	SDL_Renderer	*render;
	SDL_Renderer	*rendermap;
	SDL_Window		*window;
}					t_s;

void				ft_init_map(t_s *s);
void				ft_draw_rect(t_s *s, SDL_Texture *txr, int high, int width);
unsigned char		*ft_tga_to_str(const char *path, int alpha);
void				ft_swap_pos(t_s *s, int mode, int x, int y);
void				ft_swap_ray(t_s *s, int mode, int x, int y);
void				ft_rcasting(t_s *s);
void				ft_dir_player(t_s *s, int i);
float				ft_dir_raycasting(t_s *s);
void				ft_dir_raycasting1(t_s *s, float angle, float angle2);
void				ft_dir_raycasting2(t_s *s, float angle, float angle2);
void				ft_change_dir(t_s *s, int i);
int					ft_hitbox(t_s *s, int key);
void				ft_check_post_pars(t_s *s);
void				ft_check(t_s *s, char *av);
void				ft_init_struct(t_s *s);
void				ft_parsing(t_s *s, char *av);
void				ft_display(t_s *s);
void				ft_usage(int usage);
void				ft_draw_minimap(t_s *s);
int					ft_choise_drawtex(t_s *s, int x, int y, int xend, int hp);
#endif
