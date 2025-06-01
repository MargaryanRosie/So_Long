// //the computer has a system that is responsible for displaying visuals, handling window operations, and processing user inputs ...
// //to interact with that system we need to connect the MiniLibX with it

// //mlx = mlx_init();       with this it connects to this graphical system 
// //MiniLibX asks to do somethig and the graphical system does it
// //But MLX doesn't work alone, it internally uses X11 functions to draw the window.

// // #include "mlx/mlx.h"          //use "mlx.h" not <mlx.h> becuase it will first search in the current directory

// // int main()
// // {
// // 	void *mlx;
// // 	void *window;

// // 	mlx = mlx_init();
// // 	if (!mlx)
// //         return (1);
// // 	window = mlx_new_window(mlx, 800, 600, "So Long");    //mlx parameter is the connection
// // 	if (!window)
// //         return (1);
// // 	//this requests the OS to allocate space for a new window 
// // 	//at this stage window already exists but it doesnt react to user input yet
// // 	mlx_loop(mlx);    //this keeps the window open until the user closes it

// // 	return 0;
// // }



// //cc -Wall -Wextra -Werror main.c -Imlx -Lmlx -lmlx -lXext -lX11 -lm -o so_long


// // void *mlx_init(void);
// // void *mlx_new_window(void *mlx_ptr, int width, int height, char *title);
// // void *mlx_xpm_file_to_image(void *mlx_ptr, char *filename, int *width, int *height);
// // example:    game->img_wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &size, &size);
// // int mlx_put_image_to_window(void *mlx_ptr, void *win_ptr, void *img_ptr, int x, int y);
// // int mlx_loop(void *mlx_ptr);
// // int mlx_key_hook(void *win_ptr, int (*funct_ptr)(), void *param);
// // int mlx_destroy_window(void *mlx_ptr, void *win_ptr);

#include "so_long.h"
#include <stdio.h>

int	main(void)
{
	t_game	game;
	char	temp_map[10000];

	//Read the raw map into a string
	if (read_map("maps/level1.ber", temp_map) != 0)
	{
		write(2, "Error: Failed to read map\n", 27);
		return (1);
	}
	printf("temp_map: %s", temp_map);

	//Convert string to 2D map array
	game.map = fill_2d_array(temp_map);
	if (!game.map)
	{
		write(2, "Error: Failed to convert map\n", 30);
		return (1);
	}
	int i = 0;
	int j = 0;
	while (game.map[i])
	{
		while (game.map[i][j])
		{
			printf("%c", game.map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}

	//Validate
	if (!validate_map(game.map))
	{
		write(2, "Error: Invalid map\n", 19);
		free_map(game.map, count_lines(temp_map));
		return (1);
	}

	//Initialize game
	game_init(&game, game.map);   
	load_images(&game);           

	draw_map(&game);

	mlx_loop(game.mlx);
	return (0);
}

