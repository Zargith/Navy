/*
** EPITECH PROJECT, 2018
** printing_function.c
** File description:
** some printing functions.
*/

#include <signal.h>
#include "navy.h"

void print_coord(int x, int y)
{
	my_putchar(x + 'A' - 1);
	my_put_nbr(y);
	my_putstr(": ");
}

void print_if_touched(int touched, char *str)
{
	if (touched == TOUCHED) {
		my_putstr(str);
		my_putstr(": hit\n");
	}
	else {
		my_putstr(str);
		my_putstr(": missed\n");
	}
}
