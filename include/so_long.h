#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

int count_lines(char *temp_map);
int line_length(char *temp_map);
char **allocate_map(int line_count);
char *allocate_line(int line_length);
void free_map(char **map_2d, int rows_allocated);
int read_map(char *filename, char *temp_map);
char **fill_2d_array(char *temp_map);
void fill_line(char *line, char *temp_map, int *index);
int is_valid_path(char **map);
int check_if_unreachable(char **copy);
void flood_fill(char **map, int x, int y);
char **copy_map(char **map);
void find_player(char **map, int *x, int *y);
char *ft_strdup(char *str);
