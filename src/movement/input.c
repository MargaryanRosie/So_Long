#include "../include/so_long.h"

int	handle_keypress(int keycode, t_game *game)
{
	if (keycode == 65307)
	{
		write(2, "Game Closed!\n", 13);
		exit_game(game);
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

void	print_moves(int moves)
{
	write(1, "Moves: ", 7);
	ft_putnbr(moves);
	write(1, "\n", 1);
}
