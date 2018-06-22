/*
** EPITECH PROJECT, 2018
** parsing_file.c
** File description:
** check the ships position in the file.
*/

#include "navy.h"

char **check_ships_coord(char **file)
{
	int i = 0;
	int size = 0;

	for (i = 0; file[i] != NULL; i++) {
		if (file[i][2] != file[i][5] && file[i][3] != file[i][6])
			return (free_map(file));
		if (check_coord_chara(file[i][2], file[i][3], \
file[i][5], file[i][6]) == -1)
			return (free_map(file));
		size = file[i][0] - '0';
		if (check_size_and_coord(size, file[i]) == -1)
			return (free_map(file));
	}
	return (file);
}

char **check_ships_size(char **file)
{
	int size = 2;
	int i = 0;

	for (size = 2; size <= 5; size++) {
		for (i = 0; file[i] != NULL && file[i][0] != (size + '0'); i++);
		if (file[i] == NULL)
			return (free_map(file));
	}
	return (file);
}

char **check_size_line(char **file)
{
	int i = 0;

	for (i = 0; file[i] != NULL; i++) {
		if (my_strlen(file[i]) != 7)
			return (free_map(file));
		if (file[i][1] != ':' || file[i][4] != ':')
			return (free_map(file));
	}
	return (file);
}

char **parsing_file(char **file)
{
	if (check_size_line(file) == NULL)
		return (NULL);
	if (check_ships_size(file) == NULL)
		return (NULL);
	if (check_ships_coord(file) == NULL)
		return (NULL);
	return (file);
}
