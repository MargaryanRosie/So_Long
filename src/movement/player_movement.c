#include "../include/so_long.h"

static void	print_moves(int moves)
{
	write(1, "Moves: ", 7);
	ft_putnbr(moves);
	write(1, "\n", 1);
}

static void	check_exit(t_game *game)
{
	if (game->collectibles == 0)
	{
		(game->moves)++;
		print_moves(game->moves);
		write(1, "You Won !\n", 11);
		exit_game(game);
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

static int	handle_tile(t_game *game, char new_tile)
{
	if (new_tile == 'C')
		(game->collectibles)--;
	if (new_tile == 'E')
	{
		check_exit(game);
		return (0);
	}
	if (new_tile == 'M')
	{
		write(1, "Game Over! You were caught by an enemy!\n", 41);
		exit_game(game);
	}
	return (1);
}

static int	is_valid_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_y >= game->height
		|| new_x >= ft_strlen(game->map[new_y]))
		return (0);
	if (game->map[new_y][new_x] == '1')
		return (0);
	return (1);
}

void	move_player(t_game *game, int h, int v)
{
	int		new_x;
	int		new_y;
	char	new_tile;

	new_x = game->player_x + h;
	new_y = game->player_y + v;
	if (is_valid_move(game, new_x, new_y) == 0)
		return ;
	new_tile = game->map[new_y][new_x];
	set_player_direction(game, h, v);
	if (!handle_tile(game, new_tile))
		return ;
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'P';
	game->player_x = new_x;
	game->player_y = new_y;
	(game->moves)++;
	print_moves(game->moves);
	draw_map(game);
}
