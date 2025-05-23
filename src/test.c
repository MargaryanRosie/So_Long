#include <stdio.h>
#include "so_long.h"

int main()
{
	char temp_map[1000];
	char **map_2d;
	int valid_path;

	read_map("maps/level1.ber", temp_map);
	map_2d = fill_2d_array(temp_map);

	valid_path = is_valid_path(map_2d);

	printf("%d\n", valid_path);

	return 0;
}