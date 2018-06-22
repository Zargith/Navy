/*
** EPITECH PROJECT, 2018
** check_size_ships.c
** File description:
** check the size with the coord in the file.
*/

#include "navy.h"

int check_size_and_coord_left(int size, char *str)
{
	int size_coord = 0;

	size_coord = str[2] - str[5];
	if (size_coord < 0) {
		size_coord -= 1;
		size_coord *= -1;
	} else
		size_coord += 1;
	if (size_coord != size)
		return (-1);
	return (0);
}

int check_size_and_coord_right(int size, char *str)
{
	int size_coord = 0;

	size_coord = str[3] - str[6];
	if (size_coord < 0) {
		size_coord -= 1;
		size_coord *= -1;
	} else
		size_coord += 1;
	if (size_coord != size)
		return (-1);
	return (0);
}

int check_size_and_coord(int size, char *str)
{
	if (str[2] == str[5]) {
		if (check_size_and_coord_right(size, str) == 0)
			return (0);
	}
	if (str[3] == str[6]) {
		if (check_size_and_coord_left(size, str) == 0)
			return (0);
	}
	return (-1);
}
