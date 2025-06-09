#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>
#include <../mlx/mlx.h>

#define TILE_SIZE 96

typedef struct s_enemy
{
	int	x;
	int	y;
	int	dx;               //horizontal
	int dy;               //vertical
}t_enemy;

typedef struct s_game
{
	void	*mlx;
	void	*window;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		moves;
	int		collectibles;

	t_enemy enemies[100];
	void	*enemy_images[4];
	int enemy_count;
	void	*collectible_images[3];
	int	collectible_image;
	
	void	*img_wall_ml;
	void	*img_wall_rd;
	void	*img_wall_dl;
	void	*img_wall_dm;
	void	*img_wall_rm;
	void	*img_wall_tl;
	void	*img_wall_tm;
	void	*img_wall_tr;
	void	*img_wall_stone;
	void	*img_floor;
	void	*img_player;
	void	*img_player_r;
	void	*img_player_b;
	void	*img_player_f;
	void	*img_player_l;
	void	*img_enemy_l;
	void	*img_enemy_f;
	void	*img_enemy_b;
	void	*img_enemy_r;
	void	*img_enemy;
	void	*img_exit;
	void	*img_collectible;
	void	*img_collectible_2;
	void	*img_collectible_3;
} t_game;


typedef struct s_counter
{
	int	p;
	int	c;
	int	e;
	int	enm;
}t_counter;


typedef struct s_components
{
	int	collectibles;
	int	walls;
	int	space;
	int	enemy;
}t_components;

int		count_lines(char *temp_map);
int		line_length(char *temp_map);
char	**allocate_map(int line_count);
char	*allocate_line(int line_length);
void	free_map(char **map_2d, int rows_allocated);
int		read_map(char *filename, char *temp_map);
char	**fill_2d_array(char *temp_map);
void	fill_line(char *line, char *temp_map, int *index);
int		is_valid_path(char **map);
int		check_if_unreachable(char **copy);
void	flood_fill(char **map, int x, int y);
char	**copy_map(char **map);
void	find_player(char **map, int *x, int *y);
char	*ft_strdup(char *str);
int		has_valid_components(char **map);
int		has_basic_components(char **map);
int		has_valid_num_of_elements(char **map);
int		validate_structure(char **map);
int		validate_content(char **map);
int		validate_map(char **map);
int		is_rectangular(char **map);
int		is_surrounded_by_walls(char **map);
int		ft_strlen(char *s);
void	draw_tile(t_game *game, void *img, int x, int y);
void	draw_map(t_game *game);
void	game_init(t_game *game, char **map);
void	load_images(t_game *game);
void	draw_background(t_game *game);
void	draw_wall(t_game *game, int x, int y);
void	ft_putchar(char c);
void	ft_putnbr(int n);
int		handle_keypress(int keycode, t_game *game);
void	move_player(t_game *game, int h, int v);
int		exit_game(t_game *game);
void	free_all(t_game *game);
void	update_enemy_position(t_game *game);
int		update_enemy_position_loop(void *parameter);
char	*ft_itoa(int n);
char	*ft_strjoin(char *s1, char	*s2);
void	display_move_count(t_game *game);

#endif