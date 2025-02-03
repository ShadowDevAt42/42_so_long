#include "so_long.h"

void	free_ptr(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (!game->map)
		return ;
	while (game->map[i])
	{
		free_ptr((void **)&game->map[i]);
		i++;
	}
	free_ptr((void **)&game->map);
}