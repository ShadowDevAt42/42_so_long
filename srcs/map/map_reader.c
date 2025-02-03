#include "../../includes/so_long.h"

static int	get_map_height(char *filename)
{
	int		fd;
	int		lines;
	char	*line;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	lines = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		lines++;
	}
	close(fd);
	return (lines);
}

static int	init_map_struct(t_game *game, char *filename)
{
	game->height = get_map_height(filename);
	if (game->height <= 0)
		return (0);
	game->map = ft_calloc(game->height + 1, sizeof(char *));
	return (game->map != NULL);
}

static int	process_line(char *line, t_game *game, int i)
{
	size_t	len;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	if (i == 0)
		game->width = ft_strlen(line);
	else if (ft_strlen(line) != (size_t)game->width)
		return (0);
	game->map[i] = line;
	return (1);
}

static int	read_map_lines(t_game *game, int fd)
{
	int		i;
	char	*line;

	i = 0;
	while (i < game->height)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!process_line(line, game, i))
		{
			free(line);
			return (0);
		}
		i++;
	}
	game->map[i] = NULL;
	return (i == game->height);
}

int	read_map(t_game *game, char *filename)
{
	int	fd;
	int	result;

	if (!init_map_struct(game, filename))
		return (0);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	result = read_map_lines(game, fd);
	if (!result)
		free_map(game);
	close(fd);
	return (result);
}