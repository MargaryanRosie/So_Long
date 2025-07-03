#include "../include/so_long_bonus.h"

static void	set_game_state(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->collectibles++;
			j++;
		}
		i++;
	}
}

void	game_init(t_game *game, char **map)
{
	game->map = map;
	game->height = 0;
	while (map[game->height])
	{
		game->height++;
	}
	if (map[0] != NULL)
		game->width = ft_strlen(map[0]);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * TILE_SIZE,
			game->height * TILE_SIZE, "So Long Bonus");
	game->moves = 0;
	game->collectibles = 0;
	game->collectible_image = 0;
	game->enemy_count = count_enemies(map);
	game->enemies = malloc(sizeof(t_enemy) * game->enemy_count);
	if (!game->enemies)
	{
		write(2, "Malloc failed for enemies\n", 26);
		return ;
	}
	set_game_state(game);
	enemy_init(game);
}