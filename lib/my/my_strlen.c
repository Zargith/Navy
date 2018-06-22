/*
** EPITECH PROJECT, 2017
** my_strlen.c
** File description:
** To know the len of a str.
*/

#include <my.h>

int my_strlen(char const *str)
{
	int count = 0;

	if (str == NULL)
		return (0);
	while (str[count] != '\0')
		count++;
	return (count);
}
