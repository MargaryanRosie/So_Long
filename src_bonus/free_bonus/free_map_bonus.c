#include "../include/so_long_bonus.h"

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

void	destroy_images_1(t_game *game)
{
	if (!game)
		return ;
	if (game->img_exit)
		mlx_destroy_image(game->mlx, game->img_exit);
	if (game->img_collectible)
		mlx_destroy_image(game->mlx, game->img_collectible);
	if (game->img_floor)
		mlx_destroy_image(game->mlx, game->img_floor);
	if (game->img_player_b)
		mlx_destroy_image(game->mlx, game->img_player_b);
	if (game->img_player_f)
		mlx_destroy_image(game->mlx, game->img_player_f);
	if (game->img_player_l)
		mlx_destroy_image(game->mlx, game->img_player_l);
	if (game->img_player_r)
		mlx_destroy_image(game->mlx, game->img_player_r);
	if (game->img_wall_dl)
		mlx_destroy_image(game->mlx, game->img_wall_dl);
	if (game->img_wall_dm)
		mlx_destroy_image(game->mlx, game->img_wall_dm);
	if (game->img_wall_ml)
		mlx_destroy_image(game->mlx, game->img_wall_ml);
	if (game->img_wall_rd)
		mlx_destroy_image(game->mlx, game->img_wall_rd);
}

void	destroy_images_2(t_game *game)
{
	if (!game)
		return ;
	if (game->img_wall_tl)
		mlx_destroy_image(game->mlx, game->img_wall_tl);
	if (game->img_wall_tm)
		mlx_destroy_image(game->mlx, game->img_wall_tm);
	if (game->img_wall_tr)
		mlx_destroy_image(game->mlx, game->img_wall_tr);
	if (game->img_collectible_2)
		mlx_destroy_image(game->mlx, game->img_collectible_2);
	if (game->img_collectible_3)
		mlx_destroy_image(game->mlx, game->img_collectible_3);
	if (game->img_enemy_b)
		mlx_destroy_image(game->mlx, game->img_enemy_b);
	if (game->img_enemy_f)
		mlx_destroy_image(game->mlx, game->img_enemy_f);
	if (game->img_enemy_l)
		mlx_destroy_image(game->mlx, game->img_enemy_l);
	if (game->img_enemy_r)
		mlx_destroy_image(game->mlx, game->img_enemy_r);
	if (game->img_wall_rm)
		mlx_destroy_image(game->mlx, game->img_wall_rm);
	if (game->img_wall_stone)
		mlx_destroy_image(game->mlx, game->img_wall_stone);
}

void	free_all(t_game *game)
{
	destroy_images_1(game);
	destroy_images_2(game);
	if (game->window)
		mlx_destroy_window(game->mlx, game->window);
	if (game->enemies)
		free(game->enemies);
	mlx_destroy_display(game->mlx);
	free_map(game->map, game->height);
	free(game->mlx);
}

int	exit_game(t_game	*game)
{
	free_all(game);
	exit(0);
}
