/*
** EPITECH PROJECT, 2018
** put_file_in_map.c
** File description:
** Recup the ships position in the file.
*/

#include "navy.h"

char **put_in_map_horizontal(char **map, int size, vector2i beg)
{
	int i = 0;

	for (i = 0; i < size; i++, beg.x++) {
		if (map[beg.y][beg.x] != '.') {
			write(2, "Error: Invalid file\n", 20);
			return (free_map(map));
		}
		map[beg.y][beg.x] = size + '0';
	}
	return (map);
}

char **put_in_map_vertical(char **map, int size, vector2i beg)
{
	int i = 0;

	for (i = 0; i < size; i++, beg.y++) {
		if (map[beg.y][beg.x] != '.') {
			write(2, "Error: Invalid file\n", 20);
			return (free_map(map));
		}
		map[beg.y][beg.x] = size + '0';
	}
	return (map);
}

char **put_ship_in_map(char **map, char *file)
{
	int size = file[0] - '0';
	vector2i beg;

	if (file[2] == file[5]) {
		beg.x = file[2] - 'A';
		if (file[3] < file[6])
			beg.y = file[3] - '0' - 1;
		else
			beg.y = file[6] - '0' - 1;
		map = put_in_map_vertical(map, size, beg);
	} else {
		beg.y = file[3] - '0' - 1;
		if (file[2] < file[5])
			beg.x = file[2] - 'A';
		else
			beg.x = file[5] - 'A';
		map = put_in_map_horizontal(map, size, beg);
	}
	return (map);
}

char **put_file_in_map(char **map, char **file)
{
	int i = 0;

	if (parsing_file(file) == NULL) {
		write(2, "Error: Invalid file\n", 20);
		return (free_map(map));
	}
	for (i = 0; file[i] != NULL; i++) {
		map = put_ship_in_map(map, file[i]);
		if (map == NULL) {
			free_map(file);
			return (NULL);
		}
	}
	return (map);
}
