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

// void	free_all(t_game *game)
// {
// 	mlx_destroy_image(game->mlx, game->img_exit);
// 	mlx_destroy_image(game->mlx, game->img_collectible);
// 	mlx_destroy_image(game->mlx, game->img_floor);
// 	mlx_destroy_image(game->mlx, game->img_player);
// 	mlx_destroy_image(game->mlx, game->img_player_b);
// 	mlx_destroy_image(game->mlx, game->img_player_f);
// 	mlx_destroy_image(game->mlx, game->img_player_l);
// 	mlx_destroy_image(game->mlx, game->img_player_r);
// 	mlx_destroy_image(game->mlx, game->img_wall_dl);
// 	mlx_destroy_image(game->mlx, game->img_wall_dm);
// 	mlx_destroy_image(game->mlx, game->img_wall_ml);
// 	mlx_destroy_image(game->mlx, game->img_wall_rd);
// 	mlx_destroy_image(game->mlx, game->img_wall_rm);
// 	mlx_destroy_image(game->mlx, game->img_wall_stone);
// 	mlx_destroy_image(game->mlx, game->img_wall_tl);
// 	mlx_destroy_image(game->mlx, game->img_wall_tm);
// 	mlx_destroy_image(game->mlx, game->img_wall_tr);
// 	mlx_destroy_window(game->mlx, game->window);
// 	free_map(game->map, game->height);
// }

// int	exit_game(t_game *game)
// {
// 	free_map(game->map, game->height);
// 	mlx_destroy_window(game->mlx, game->window);
// 	exit(0);
// }