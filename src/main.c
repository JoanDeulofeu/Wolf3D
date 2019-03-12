#include "wolf3d.h"

void	ft_usage(int usage)
{
	if (usage == -1)
		ft_putstr("Error : Malloc failed\n");
	if (usage == 1)
		ft_putstr("Usage : ./Wolf3d map_file.txt\n");
	if (usage == 2)
		ft_putstr("Warning : Invalid file\n");
	if (usage == 3)
		ft_putstr("Warning : Invalid file (place one player)\n");
	if (usage == 4)
		ft_putstr("Warning : Invalid file (surround map w/ wall)\n");
	if (usage == 5)
		ft_putstr("Warning : Invalid file (value not in range)\n");
	if (usage == 6)
		printf("Erreur de chargement de l'image : %s\n",SDL_GetError());
	if (usage == 7)
		printf("Erreur de chargement de texture\n");
	exit(0);
}

int main(int ac, char **av)
{
	t_s *s;
	if (ac != 2)
		ft_usage(1);
	if (!(s = (t_s *)malloc(sizeof(t_s))))
		return (0);
	s->high = 0;
	s->width = 0;
	printf("test1\n");
	ft_check(s, av[1]);
	printf("test2\n");
	ft_init_struct(s);
	printf("test3\n");
	ft_parsing(s, av[1]);
	// s->tex->test = ft_tga(s, "textures/felix.tga");
	// ft_tga(s, "textures/Maxence.tga");
	printf("test4\n");
	ft_display(s);
	return (0);
}
