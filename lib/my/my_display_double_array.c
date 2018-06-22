/*
** EPITECH PROJECT, 2018
** my_display_double_array.c
** File description:
** Display a double array.
*/

#include "my.h"

void my_display_double_array(char **array)
{
	for (int y = 0; array[y]; y++) {
		for (int x = 0; array[y][x] != '\0'; x++)
			my_putchar(array[y][x]);
		my_putchar('\n');
	}
	my_putchar('\n');
}
