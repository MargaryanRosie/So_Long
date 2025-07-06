#include "../include/so_long.h"

void	free_map(char **map_2d, int rows_allocated)
{
	int	i;

	if (!map_2d)
		return ;
	i = 0;
	while (i < rows_allocated)
	{
		free(map_2d[i]);
		i++;
	}
	free(map_2d);
}

static void	free_images(t_game *game)
{
	if (game->img_player_b)
		mlx_destroy_image(game->mlx, game->img_player_b);
	if (game->img_player_f)
		mlx_destroy_image(game->mlx, game->img_player_f);
	if (game->img_player_l)
		mlx_destroy_image(game->mlx, game->img_player_l);
	if (game->img_player_r)
		mlx_destroy_image(game->mlx, game->img_player_r);
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
}

static void	free_wall_images(t_game *game)
{
	if (game->img_wall_dl)
		mlx_destroy_image(game->mlx, game->img_wall_dl);
	if (game->img_wall_dm)
		mlx_destroy_image(game->mlx, game->img_wall_dm);
	if (game->img_wall_ml)
		mlx_destroy_image(game->mlx, game->img_wall_ml);
	if (game->img_wall_rd)
		mlx_destroy_image(game->mlx, game->img_wall_rd);
	if (game->img_wall_rm)
		mlx_destroy_image(game->mlx, game->img_wall_rm);
	if (game->img_wall_stone)
		mlx_destroy_image(game->mlx, game->img_wall_stone);
	if (game->img_wall_tl)
		mlx_destroy_image(game->mlx, game->img_wall_tl);
	if (game->img_wall_tm)
		mlx_destroy_image(game->mlx, game->img_wall_tm);
	if (game->img_wall_tr)
		mlx_destroy_image(game->mlx, game->img_wall_tr);
}

void	free_all(t_game *game)
{
	free_images(game);
	free_wall_images(game);
	mlx_destroy_display(game->mlx);
	free_map(game->map, game->height);
	free(game->mlx);
}

int	exit_game(t_game *game)
{
	free_all(game);
	exit(0);
}
