#include "../include/so_long_bonus.h"

// static int	tile_is_walkable(char c)
// {
// 	if (c == 'P' || c == '0')
// 		return (1);
// 	return (0);
// }

// static int	do_step(t_game *game, int i, int dx, int dy)
// {
// 	int	new_x;
// 	int	new_y;

// 	new_x = game->enemies[i].x + dx;
// 	new_y = game->enemies[i].y + dy;
// 	if (new_x < 0 || new_y < 0 || new_x >= game->width || new_y >= game->height)
// 		return (0);
// 	if (!tile_is_walkable(game->map[new_y][new_x]) &&
// 		game->map[new_y][new_x] != 'P')
// 		return (0);
// 	if (game->map[new_y][new_x] == 'P')
// 	{
// 		write(1, "Game Over! You were caught by an enemy!\n", 40);
// 		exit_game(game);
// 	}
// 	game->map[game->enemies[i].y][game->enemies[i].x] = '0';
// 	game->map[new_y][new_x] = 'M';
// 	game->enemies[i].x = new_x;
// 	game->enemies[i].y = new_y;
// 	game->enemies[i].dx = dx;
// 	game->enemies[i].dy = dy;
// 	return (1);
// 	return (1);
// }

// static void	step_the_enemy(t_game *game, int i)
// {
// 	static int	dir[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
// 	int			j;
// 	int			rand;
// 	int			k;

// 	if (do_step(game, i, game->enemies[i].dx, game->enemies[i].dy))
// 		return ;
// 	rand = (i + game->enemies[i].x + game->enemies[i].y) % 4;
// 	j = 0;
// 	while (j < 4)
// 	{
// 		k = (j + rand) % 4;
// 		if (do_step(game, i, dir[k][0], dir[k][1]))
// 			return ;
// 		j++;
// 	}
// }

// void	update_enemy_position(t_game *game)
// {
// 	int	i;

// 	i = 0;
// 	while (i < game->enemy_count)
// 	{
// 		step_the_enemy(game, i);
// 		i++;
// 	}
// }

int		update_loop(void *parameter)
{
	static int	count = 0;
	t_game		*game;

	game = (t_game *)parameter;
	count++;
	if (count % 1000 == 0)
	{
		draw_map(game);
		count = 0;
		game->collectible_image = (game->collectible_image + 1) % 3;
	}
	return (0);
}