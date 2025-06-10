#include "../include/so_long_bonus.h"
#include <stdio.h>

static void	check_map(t_game *game, char *s, char *temp_map)
{
	int	i;

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

	int result = validate_map(game->map);

	i = 0;
	while(game->map[i])
		i++;
	if (!result)
	{
		printf("freeing map with height %d\n", i);
		free_map(game->map, i);
		exit(3);
	}
}

int	main(int argc, char *argv[])
{
	printf("1");
	t_game	game = {0};
	char	temp_map[1000] = {0};

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of parameters\n", 36);
		return (1);
	}
	printf("2");
	check_map(&game, argv[1], temp_map);
	printf("check map done\n");

	if (!game.map)
	{
		write(2, "Error: Map is NULL!\n", 20);
		exit(1);
	}

	game_init(&game, game.map);
	printf("game init done\n");
	load_images(&game);
	printf("load images done\n");
	draw_map(&game);
	printf("draw map done");

	if (!game.mlx)
	{
		write(2, "Error\nmlx initialization failed!\n", 34);
		exit(1);
	}
	if (!game.window)
	{
		write(2, "Error\nWindow creation failed!\n", 31);
		exit(1);
	}
	mlx_key_hook(game.window, handle_keypress, &game);          //this calls the function with the data given for your opened window
	mlx_loop_hook(game.mlx, update_enemy_position_loop, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
}



