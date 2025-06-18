#include "../include/so_long_bonus.h"

void	draw_tile(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_wall(t_game *game, int x, int y)
{
	int	last_col;
	int	last_row;

	last_col = game->width - 1;
	last_row = game->height - 1;
	if (x > 0 && y > 0 && x < last_col && y < last_row)
		draw_tile(game, game->img_wall_stone, x, y);
	if (x == 0 && y == 0)
		draw_tile(game, game->img_wall_tl, x, y);
	else if (x == last_col && y == 0)
		draw_tile(game, game->img_wall_tr, x, y);
	else if (x == 0 && y == last_row)
		draw_tile(game, game->img_wall_dl, x, y);
	else if (x == last_col && y == last_row)
		draw_tile(game, game->img_wall_rd, x, y);
	else if (y == 0)
		draw_tile(game, game->img_wall_tm, x, y);
	else if (y == last_row)
		draw_tile(game, game->img_wall_dm, x, y);
	else if (x == 0)
		draw_tile(game, game->img_wall_ml, x, y);
	else if (x == last_col)
		draw_tile(game, game->img_wall_rm, x, y);
}

void	draw_enemy_tile(t_game *game, int j, int i)
{
	int	k;

	k = 0;
	while (k < game->enemy_count)
	{
		if (game->enemies[k].x == j && game->enemies[k].y == i)
		{
			if (game->enemies[k].dx == -1)
				draw_tile(game, game->img_enemy_l, j, i);
			else if (game->enemies[k].dx == 1)
				draw_tile(game, game->img_enemy_r, j, i);
			else if (game->enemies[k].dy == -1)
				draw_tile(game, game->img_enemy_f, j, i);
			else if (game->enemies[k].dy == 1)
				draw_tile(game, game->img_enemy_b, j, i);
			break ;
		}
		k++;
	}
}

static void	draw_map_tile(t_game *game, char tile, int x, int y)
{
	if (tile == '0')
		draw_tile(game, game->img_floor, x, y);
	else if (tile == '1')
		draw_wall(game, x, y);
	else if (tile == 'P')
		draw_tile(game, game->img_player, x, y);
	else if (tile == 'C')
		draw_tile(game,
			game->collectible_images[game->collectible_image], x, y);
	else if (tile == 'E')
		draw_tile(game, game->img_exit, x, y);
	else if (tile == 'M')
		draw_enemy_tile(game, x, y);
}

void	draw_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			draw_map_tile(game, game->map[i][j], j, i);
			j++;
		}
		i++;
	}
	display_move_count(game);
}
