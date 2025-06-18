#include "../include/so_long.h"

void	draw_wall(t_game *game, int x, int y)
{
	int	last_col;
	int	last_row;

	last_row = game->height - 1;
	last_col = game->width - 1;
	if (x > 0 && y > 0 && x < last_col && y < last_row)
	{
		draw_tile(game, game->img_wall_stone, x, y);
	}
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
