/*
** EPITECH PROJECT, 2018
** my_putchar_error.c
** File description:
** Function my_putchar but write in error exit.
*/

#include <unistd.h>

void my_putchar_error(char c)
{
	write(2, &c, 1);
}
