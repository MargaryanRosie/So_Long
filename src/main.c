
#include "../include/so_long.h"
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
		write(2, "Error\nFailed to clean up the map\n", 33);
		exit(2);
	}
	game->map = fill_2d_array(cleaned);
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
	t_game	game = {0};
	char	temp_map[1000] = {0};

	if (argc != 2)
	{
		write(2, "Error\nInvalid number of parameters\n", 36);
		return (1);
	}
	check_map(&game, argv[1], temp_map);
	if (!game.map)
	{
		write(2, "Error: Map is NULL!\n", 21);
		exit(1);
	}

	game_init(&game, game.map);
	load_images(&game);
	draw_map(&game);

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
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}



