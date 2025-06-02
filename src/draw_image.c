#include "so_long.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * TILE_SIZE, y * TILE_SIZE);       //It draws one image (tile) on the window at a specific location.
} 


// void	draw_background(t_game *game)
// {
// 	int	i;
// 	int	j;

// 	i = 0;
// 	while (i < game->height)
// 	{
// 		j = 0;
// 		while (j < game->width)
// 		{
// 			draw_tile(game, game->img_floor, j, i);  // Draw the floor tile at each position
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_map(t_game *game)
{
	int		i;
	int		j;
	char	tile;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			tile = game->map[i][j];
	
			if (tile == '0')
				draw_tile(game, game->img_floor, j, i);
			else if (tile == '1')
				draw_wall(game, j, i);
			else if (tile == 'P')
				draw_tile(game, game->img_player, j, i);
			else if (tile == 'C')
				draw_tile(game, game->img_collectible, j, i);
			else if (tile == 'E')
				draw_tile(game, game->img_exit, j, i);
			j++;
		}
		i++;
	}
}
