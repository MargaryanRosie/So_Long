#include "../include/so_long_bonus.h"
#include <stdio.h>

static void	fill_game_map(t_game *game, int fd)
{
	int		i;
	int		result;

	if (!game)
		exit((close(fd), 1));
	game->map = get_2d_array(fd);
	if (!game->map)
	{
		write(2, "Error\nFailed to convert map\n", 28);
		exit((close(fd), 3));
	}
	result = validate_map(game->map);
	i = 0;
	while (game->map[i])
		i++;
	if (!result)
	{
		free_map(game->map, i);
		exit((close(fd), 4));
	}
}

static void	check_args(int argc)
{
	if (argc != 2)
	{
		write(2, "Error\nInvalid number of parameters\n", 35);
		exit(1);
	}
}

static void	check_filename(char *filename)
{
	if (!validate_file_name(filename))
	{
		write(2, "Error\nInvalid file extension\n", 29);
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
		mlx_destroy_display(game->mlx);
		write(2, "Error\nWindow creation failed!\n", 31);
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	t_game	game;
	int		fd;

	check_args(argc);
	check_filename(argv[1]);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nNo such file\n", 19);
		return (1);
	}
	fill_game_map(&game, fd);
	close(fd);
	if (!game.map)
		exit(1);
	game_init(&game, game.map);
	load_images(&game);
	draw_map(&game);
	check_window(&game);
	mlx_key_hook(game.window, handle_keypress, &game);
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}