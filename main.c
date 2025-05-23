//the computer has a system that is responsible for displaying visuals, handling window operations, and processing user inputs ...
//to interact with that system we need to connect the MiniLibX with it

//mlx = mlx_init();       with this it connects to this graphical system 
//MiniLibX asks to do somethig and the graphical system does it
//But MLX doesn't work alone, it internally uses X11 functions to draw the window.

// #include "mlx/mlx.h"          //use "mlx.h" not <mlx.h> becuase it will first search in the current directory

// int main()
// {
// 	void *mlx;
// 	void *window;

// 	mlx = mlx_init();
// 	if (!mlx)
//         return (1);
// 	window = mlx_new_window(mlx, 800, 600, "So Long");    //mlx parameter is the connection
// 	if (!window)
//         return (1);
// 	//this requests the OS to allocate space for a new window 
// 	//at this stage window already exists but it doesnt react to user input yet
// 	mlx_loop(mlx);    //this keeps the window open until the user closes it

// 	return 0;
// }



//cc -Wall -Wextra -Werror main.c -Imlx -Lmlx -lmlx -lXext -lX11 -lm -o so_long


