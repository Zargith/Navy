/*
** EPITECH PROJECT, 2018
** navy_display_double_array.c
** File description:
** Display a double array for navy's project.
*/

#include "my.h"

void navy_display_double_array(char **array)
{
	int line = 1;

	my_putstr(" |A B C D E F G H\n");
	my_putstr("-+---------------\n");
	for (int y = 0; array[y]; y++) {
		my_put_nbr(line);
		my_putchar('|');
		line++;
		for (int x = 0; x < 8; x++) {
			my_putchar(array[y][x]);
			my_putchar(' ');
		}
		my_putchar('\n');
	}
}
