#include "wolf3d.h"

void	ft_init_struct(t_s *s)
{
	int i;

	i = 0;
	if (!(s->map = (t_map**)malloc(sizeof(t_map*) * s->high + 1)))
		ft_usage(-1);
	s->map[s->high] = NULL;
	while (s->map[i] != NULL)
	{
		if (!(s->map[i] = (t_map*)malloc(sizeof(t_map) * s->width + 1)))
			ft_usage(-1);
		s->map[i][s->width] = NULL;
		i++;
	}
}
