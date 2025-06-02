#include "so_long.h"


int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)                 //esc
	{
		write(2, "Game Closed!", 13);
		exit(0);
	}
	if (keycode == 'w')
		move_player(game, 0, -1);
	else if (keycode == 's')
		move_player(game, 0, 1);
	else if (keycode == 'a')
		move_player(game, -1, 0);
	else if (keycode == 'd')
		move_player(game, 1, 0);
	return (0);
}

static void print_moves(int moves)
{
	write(1, "Moves: ", 7);
	ft_putnbr(moves);
	write(1, "\n", 1);
}

static void check_exit(int collectibles, int moves)
{
	if(collectibles == 0)
		{
			(moves)++;
			print_moves(moves);
			write(1, "You Won !\n", 11);
			exit(0);
		}
}


static void	set_player_direction(t_game *game, int h, int v)
{
	if (h == 1)
		game->img_player = game->img_player_r;
	else if (h == -1)
		game->img_player = game->img_player_l;
	else if (v == 1)
		game->img_player = game->img_player_f;
	else if (v == -1)
		game->img_player = game->img_player_b;
}

void	move_player(t_game *game, int h, int v)               //horizontal, vertical movement   1-down or right -1-left or uop
{
	int	new_x;
	int new_y;
	char	new_tile;

	new_x = game->player_x + h;
	new_y = game->player_y + v;
	new_tile = game->map[new_y][new_x];

	set_player_direction(game, h, v);

	if(new_tile == '1')
		return;
	if (new_tile == 'C')
		(game->collectibles)--;
	if(new_tile == 'E')
	{
		check_exit(game->collectibles, game->moves);
		return;
	}

	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	game->moves++;
	print_moves(game->moves);
	draw_map(game);
}

int	exit_game(t_game *game)
{
	free_map(game->map, game->height);
	mlx_destroy_window(game->mlx, game->window);
	exit(0);
	return (0);
}

