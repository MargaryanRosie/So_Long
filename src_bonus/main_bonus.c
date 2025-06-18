#include "../include/so_long_bonus.h"
#include <stdio.h>

static void	check_map(t_game *game, char *s, char *temp_map)
{
	int		i;
	int		result;
	char	*cleaned;

	if (!game)
		exit(1);
	if (read_map(s, temp_map) != 0)
	{
		write(2, "Error\nFailed to read map\n", 26);
		exit (1);
	}
	printf("temp\n%s\n", temp_map);
	cleaned = clean_map_string(temp_map);
	printf("cleaned\n%s\n", cleaned);
	if (!cleaned)
	{
		write(2, "Error\nFailed to clean up the map\n", 34);
		exit(2);
	}
	game->map = fill_2d_array(cleaned);
	int k = 0;
	while (game->map[k])
	{
		printf("%d: %saaaa\n", k, game->map[k]);
		k++;
	}
	free(cleaned);
	if (!game->map)
	{
		write(2, "Error\nFailed to convert map\n", 29);
		exit(3);
	}
	result = validate_map(game->map);

	i = 0;
	while (game->map[i])
		i++;
	if (!result)
	{
		printf("freeing map with height %d\n", i);
		free_map(game->map, i);
		exit(4);
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



