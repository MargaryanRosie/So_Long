#include <stdio.h>
#include "so_long.h"

int main()
{
	char temp_map[1000];
	char **map_2d;
	int is_valid_map;
	int rectangular;

	read_map("maps/invalid.ber", temp_map);
	map_2d = fill_2d_array(temp_map);

	is_valid_map = validate_map(map_2d);
	rectangular = is_rectangular(map_2d);


	printf("%d\n", is_valid_map);
	return 0;
}