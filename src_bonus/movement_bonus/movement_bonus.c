#include "../include/so_long_bonus.h"

static void	check_conditions(t_game *game, int new_x, int new_y, int i)
{
	if (game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'M'
				&& game->map[new_y][new_x] != 'C'
				&& game->map[new_y][new_x] != 'E')
	{
		if (game->map[new_y][new_x] == 'P')
		{
			write(1, "Game Over! You were caught by an enemy!\n", 41);
			exit_game(game);
		}
		game->map[game->enemies[i].y][game->enemies[i].x] = '0';
		game->enemies[i].x = new_x;
		game->enemies[i].y = new_y;
		game->map[new_y][new_x] = 'M';
	}
	else
	{
		game->enemies[i].dx = -game->enemies[i].dx;
		game->enemies[i].dy = -game->enemies[i].dy;
	}
}

void	update_enemy_position(t_game *game)
{
	int	i;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < game->enemy_count)
	{
		new_x = game->enemies[i].x + game->enemies[i].dx;
		new_y = game->enemies[i].y + game->enemies[i].dy;
		if (new_x >= 0 && new_x < game->width
			&& new_y >= 0 && new_y < game->height)
		{
			check_conditions(game, new_x, new_y, i);
		}
		i++;
	}
}

int		update_enemy_position_loop(void *parameter)        //loop hooky spasum e int veradardznox funkciayi, dra hamar int return type
{
	static int	count = 0;
	t_game		*game;

	game = (t_game *)parameter;
	count++;                //every time this function is called, count is incremented
	if (count > 1800)
	{
		update_enemy_position(game);
		draw_map(game);
		count = 0;
		game->collectible_image = (game->collectible_image + 1) % 3;
	}
	return (0);
}
