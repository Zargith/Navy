/*
** EPITECH PROJECT, 2018
** recup_ship.c
** File description:
** Recup the ships position in the file.
*/

#include "navy.h"

char **free_map(char **map)
{
	if (map == NULL)
		return (NULL);
	for (int y = 0; map[y] != NULL; y++)
		free(map[y]);
	free(map);
	return (NULL);
}

char **recup_ship(char **map, char *path)
{
	char **file = NULL;

	if (map == NULL || path == NULL) {
		free_map(map);
		return (NULL);
	}
	file = recup_file(path);
	if (file == NULL) {
		free_map(map);
		return (NULL);
	}
	map = put_file_in_map(map, file);
	if (map != NULL)
		file = free_map(file);
	return (map);
}
