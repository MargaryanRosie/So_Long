#include "../include/so_long_bonus.h"

int	count_enemies(char **map_2d)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map_2d[i])
	{
		j = 0;
		while (map_2d[i][j])
		{
			if (map_2d[i][j] == 'M')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	set_enemy(t_game *game, int x, int y, int count)
{
	game->enemies[count].x = x;
	game->enemies[count].y = y;
	if (count % 2 == 0)
	{
		game->enemies[count].dx = 1;
		game->enemies[count].dy = 0;
	}
	else
	{
		game->enemies[count].dx = 0;
		game->enemies[count].dy = 1;
	}
}

void	enemy_init(t_game *game)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'M')
				set_enemy(game, j, i, count++);
			j++;
		}
		i++;
	}
}