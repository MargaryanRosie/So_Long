#include "../include/so_long_bonus.h"

void	find_enemies(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->enemy_count = 0;
	while (i < game->height)
	{
		j = 0;
		while (j < game->width)
		{
			if (game->map[i][j] == 'M')
			{
				game->enemies[game->enemy_count].y = i;
				game->enemies[game->enemy_count].x = j;
				(game->enemy_count)++;
			}
			j++;
		}
		i++;
	}
}


int main()
{
	char temp[10000];

	read_map("../maps/valid_map_bonus/level1.ber", temp);

	char ** filled_2d = fill_2d_array(temp);

	t_game game;

	game_init(&game, filled_2d);
	find_enemies(&game);

	int i = 0;

	while( i < game.enemy_count)
	{
		printf("enemy %d x: %d", i, game.enemies[i].x);
		printf("enemy %d y: %d", i, game.enemies[i].y);
		printf("\n");
		i++;
	}

	return 0;
}
