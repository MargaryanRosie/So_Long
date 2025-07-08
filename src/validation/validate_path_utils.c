#include "../include/so_long_bonus.h"
#include "../get_next_line/get_next_line.h"

int	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

char	**copy_map(char **map)
{
	char	**copy;
	int		i;

	i = 0;
	while (map[i])
		i++;
	copy = (char **)malloc(sizeof(char *) * (i + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (map[i])
	{
		copy[i] = ft_strdup(map[i]);
		if (!copy[i])
		{
			free_map(copy, i);
			return (NULL);
		}
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == 'V' || map[y][x] == '1' || map[y][x] == 'E')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x + 1, y);
	flood_fill(map, x - 1, y);
	flood_fill(map, x, y + 1);
	flood_fill(map, x, y - 1);
}

int	check_if_unreachable(char **copy)
{
	int	i;
	int	j;
	int	exit_reachable;

	i = 0;
	exit_reachable = 0;
	while (copy[i])
	{
		j = 0;
		while (copy[i][j])
		{
			if (copy[i][j] == 'C')
				return (0);
			if (copy[i][j] == 'E')
				if ((i > 0 && copy[i - 1][j] == 'V') ||
					(copy[i + 1] && copy[i + 1][j] == 'V') ||
					(j > 0 && copy[i][j - 1] == 'V') ||
					(copy[i][j + 1] && copy[i][j + 1] == 'V'))
					exit_reachable = 1;
			j++;
		}
		i++;
	}
	return (exit_reachable);
}
