
#include "so_long.h"
#include <stdio.h>

int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		write(2, "Invalid number of parameters\n", 30);
		return (1);
	}
	t_game	game;
	char	temp_map[10000];

	if (read_map(argv[1], temp_map) != 0)
	{
		write(2, "Error: Failed to read map\n", 27);
		return (1);
	}
	game.map = fill_2d_array(temp_map);
	if (!game.map)
	{
		write(2, "Error: Failed to convert map\n", 30);
		return (1);
	}
	if (!validate_map(game.map))
	{
		write(2, "Error: Invalid map\n", 19);
		free_map(game.map, count_lines(temp_map));
		return (1);
	}

	game_init(&game, game.map);   
	load_images(&game);           
	//draw_background(&game);
	draw_map(&game);

	mlx_key_hook(game.window, handle_keypress, &game);          //this calls the function with the data given for your opened window
	mlx_hook(game.window, 17, 0, exit_game, &game);
	mlx_loop(game.mlx);
	return (0);
}

