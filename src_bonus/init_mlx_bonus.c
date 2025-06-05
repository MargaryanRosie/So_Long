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
				game->player_x = j;                                //we set the position in the struct
				game->player_y = i;
			}
			else if (game->map[i][j] == 'C')
			{
				game->collectibles++;                       //we count the collectbles in the struct 
			}
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
	game->width = ft_strlen(map[0]);
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx, game->width * TILE_SIZE, game->height * TILE_SIZE, "So Long");
	game->moves = 0;
	game->collectibles = 0;
	set_game_state(game);
}

// int main()
// {
// 	t_game	game;
// 	char	temp_map[1000];

// 	read_map("../maps/level1.ber", temp_map);
// 	game.map = fill_2d_array(temp_map);

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

// }

