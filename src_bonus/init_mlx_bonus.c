#include "../include/so_long_bonus.h"

static void set_game_state(t_game *game)
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
			else if (game->map[i][j] == 'M')
			{
				game->enemies[game->enemy_count].x = j;
				game->enemies[game->enemy_count].y = i;
				(game->enemy_count)++;
				if (game->enemy_count >= 100)
				{
					write(2, "Error: Too many enemies!\n", 25);
					exit(1);
				}
			}
			j++;
		}
		i++;
	}
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
	game->enemy_count = 0;
	set_game_state(game);
	enemy_init(game);
}

// int main()
// {
// 	t_game	game;
// 	char	temp_map[1000];

// 	read_map("maps/valid_map_bonus/level1.ber", temp_map);
// 	char **map_2d = fill_2d_array(temp_map);

// 	// int i = 0;
// 	// int j;
// 	// while (i < 6)
// 	// {
// 	// 	j = 0;
// 	// 	while (j < 6)
// 	// 	{
// 	// 		printf("%c", game.map[i][j]);
// 	// 		j++;
// 	// 	}
// 	// 	printf("\n");
// 	// 	i++;
// 	// }
// 	game_init(&game, map_2d);
// 	printf("enemy x, y: (%d, %d)\n", game.enemies[1].x, game.enemies[1].y);

// }