/*
** EPITECH PROJECT, 2017
** my_putstr_error.c
** File description:
** my_putstr but write in error exit.
*/

#include <my.h>

void my_putstr_error(char *str)
{
	int i = 0;

	while (str[i] != '\0') {
		my_putchar_error(str[i]);
		i++;
	}
}
