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
	int		k;
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
				draw_tile(game, game->collectible_images[game->collectible_image], j, i);
			else if (tile == 'E')
				draw_tile(game, game->img_exit, j, i);
			else if (tile == 'M')                //menq gitenq vor sa enemy e, bayc chgitenq enemies[]- i vorerord enemy-n e
			{
				k = 0;
				while (k < game->enemy_count)
				{
					if(game->enemies[k].x == j && game->enemies[k].y == i)
					{
						if (game->enemies[k].dx == -1)
							draw_tile(game, game->img_enemy_l, j, i);
						else if (game->enemies[k].dx == 1)
							draw_tile(game, game->img_enemy_r, j, i);
						else if (game->enemies[k].dy == -1)
							draw_tile(game, game->img_enemy_f, j, i);
						else if (game->enemies[k].dy == 1)
							draw_tile(game, game->img_enemy_b, j, i);
						break;
					}
					k++;
				}
			}
			j++;
		}
		i++;
	}
	display_move_count(game);
}
