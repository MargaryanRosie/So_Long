// #include <stdio.h>
// #include "so_long.h"

// int main()
// {
// 	char temp_map[1000];
// 	char **map_2d;
// 	int is_valid_map;
// 	int rectangular;

// 	read_map("maps/level1.ber", temp_map);
// 	map_2d = fill_2d_array(temp_map);

// 	// is_valid_map = validate_map(map_2d);
// 	// rectangular = is_rectangular(map_2d);


// 	//printf("%d\n", is_valid_map);
// 	//printf("%s", temp_map);

// 	int i = 0;
// 	int j;
// 	while (map_2d[i])
// 	{
// 		j = 0;
// 		while (map_2d[i][j])
// 		{
// 			printf("%c", map_2d[i][j]);
// 			j++;
// 		}
// 		printf("\n");
// 		i++;
// 	}
// 	return 0;
// }