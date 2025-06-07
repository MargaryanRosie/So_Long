#include "../include/so_long_bonus.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img, x * TILE_SIZE, y * TILE_SIZE);       //It draws one image (tile) on the window at a specific location.
}

void	draw_wall(t_game *game, int x, int y)
{
	int last_col = game->width - 1;
	int last_row = game->height - 1;

	if (x > 0 && y > 0 && x < last_col && y < last_row)
	{
		draw_tile(game, game->img_wall_stone, x, y);
	}

	// Corners
	if (x == 0 && y == 0)
		draw_tile(game, game->img_wall_tl, x, y);
	else if (x == last_col && y == 0)
		draw_tile(game, game->img_wall_tr, x, y);
	else if (x == 0 && y == last_row)
		draw_tile(game, game->img_wall_dl, x, y);
	else if (x == last_col && y == last_row)
		draw_tile(game, game->img_wall_rd, x, y);

	// Edges
	else if (y == 0)
		draw_tile(game, game->img_wall_tm, x, y);
	else if (y == last_row)
		draw_tile(game, game->img_wall_dm, x, y);
	else if (x == 0)
		draw_tile(game, game->img_wall_ml, x, y);
	else if (x == last_col)
		draw_tile(game, game->img_wall_rm, x, y);

}

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
			else if (tile == 'M')
				draw_tile(game, game->img_enemy, j, i);
			j++;
		}
		i++;
	}
}
