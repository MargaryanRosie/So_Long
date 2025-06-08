#include "../include/so_long_bonus.h"
#include <stdio.h>

static void	check_map(t_game *game, char *s, char *temp_map)
{
	if (read_map(s, temp_map) != 0)
	{
		write(2, "Error\nFailed to read map\n", 26);
		exit (1);
	}
	game->map = fill_2d_array(temp_map);
	if (!game->map)
	{
		write(2, "Error\nFailed to convert map\n", 29);
		exit(2);
	}
	if (!validate_map(game->map))
	{
		free_map(game->map, game->height);
		exit(3);
	}
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of parameters\n", 36);
		return (1);
	}
	t_game	game;
	char	temp_map[10000];

	check_map(&game, argv[1], temp_map);

	game_init(&game, game.map);
	load_images(&game);
	draw_map(&game);

	mlx_key_hook(game.window, handle_keypress, &game);          //this calls the function with the data given for your opened window
	mlx_loop_hook(game.mlx, update_enemy_position_loop, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	free_all(&game);
	return (0);
}



