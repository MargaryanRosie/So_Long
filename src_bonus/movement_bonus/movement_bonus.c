#include "so_long_bonus.h"

void	update_enemy_position(t_game *game)
{
	int	i;
	int	dir;
	int	new_x;
	int	new_y;

	i = 0;
	while (i < game->enemy_count)
	{
		dir = game->enemies[i].direction;
		new_x = game->enemies[i].x + dir;
		new_y = game->enemies[i].y;

		if(game->map[new_y][new_x] != '1' && game->map[new_y][new_x] != 'M')
		{
			game->map[game->enemies[i].y][game->enemies[i].x] = '0';
			game->enemies[i].x = new_x;	
			game->map[new_y][new_x] = 'M';
		}
		else                     //change the direction if there is wall
		{
			game->enemies[i].direction = -dir;
		}
		i++;
	}
}