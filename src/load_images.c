#include "../include/so_long.h"

static void	check(t_game *game)
{
	if (!game->img_wall_ml || !game->img_wall_rd || !game->img_wall_dl
		|| !game->img_wall_dm || !game->img_wall_rm
		|| !game->img_wall_tl || !game->img_wall_tm || !game->img_wall_tr
		|| !game->img_wall_stone || !game->img_floor
		|| !game->img_player_f || !game->img_player_b || !game->img_player_r
		|| !game->img_player_l || !game->img_exit || !game->img_collectible)
	{
		write(2, "Error: Failed to load one or more textures\n", 44);
		exit(1);
	}
}

static void	load_images_1(t_game *game)
{
	int	w;
	int	h;

	game->img_wall_ml = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-ML.xpm", &w, &h);
	game->img_wall_rd = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-RD.xpm", &w, &h);
	game->img_wall_dl = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-DL.xpm", &w, &h);
	game->img_wall_dm = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-DM.xpm", &w, &h);
	game->img_wall_rm = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-RM.xpm", &w, &h);
	game->img_wall_tl = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-TL.xpm", &w, &h);
	game->img_wall_tm = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-TM.xpm", &w, &h);
	game->img_wall_tr = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-TR.xpm", &w, &h);
	game->img_wall_stone = mlx_xpm_file_to_image(game->mlx,
			"textures/wall-stone.xpm", &w, &h);
}

void	load_images_2(t_game *game)
{
	int	w;
	int	h;

	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"textures/floor.xpm", &w, &h);
	game->img_player_r = mlx_xpm_file_to_image(game->mlx,
			"textures/player-R.xpm", &w, &h);
	game->img_player_b = mlx_xpm_file_to_image(game->mlx,
			"textures/player-back.xpm", &w, &h);
	game->img_player_f = mlx_xpm_file_to_image(game->mlx,
			"textures/player-F.xpm", &w, &h);
	game->img_player_l = mlx_xpm_file_to_image(game->mlx,
			"textures/player-L.xpm", &w, &h);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"textures/exit.xpm", &w, &h);
	game->img_collectible = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img_player = game->img_player_f;     //by default
}

void	load_images(t_game *game)
{
	load_images_1(game);
	load_images_2(game);
	check(game);
}
