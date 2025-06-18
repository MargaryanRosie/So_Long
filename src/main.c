#include "../include/so_long.h"
#include <stdio.h>

static char	*read_and_clean_map(char *s, char *temp_map)
{
	char	*cleaned;

	if (read_map(s, temp_map) != 0)
	{
		write(2, "Error\nFailed to read map\n", 26);
		exit (1);
	}
	cleaned = clean_map_string(temp_map);
	if (!cleaned)
		exit(2);
	return (cleaned);
}

static void	check_map(t_game *game, char *s, char *temp_map)
{
	int		i;
	int		result;
	char	*cleaned;

	if (!game)
		exit(1);
	cleaned = read_and_clean_map(s, temp_map);
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
		free_map(game->map, i);
		exit(4);
	}
}

static void	check_args(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of parameters\n", 36);
		exit(1);
	}
}

static void	check_window(t_game *game)
{
	if (!game->mlx)
	{
		write(2, "Error\nmlx initialization failed!\n", 34);
		exit(1);
	}
	if (!game->window)
	{
		write(2, "Error\nWindow creation failed!\n", 31);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;
	char	temp_map[1000];

	check_args(argc);
	check_map(&game, argv[1], temp_map);
	if (!game.map)
	{
		write(2, "Error\nMap is NULL!\n", 20);
		exit(1);
	}
	game_init(&game, game.map);
	load_images(&game);
	draw_map(&game);
	check_window(&game);
	mlx_key_hook(game.window, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}
