/*
** EPITECH PROJECT, 2017
** my_strcpy.c
** File description:
** Function that copies a string into another.
*/

#include "my.h"

char *my_strcpy(char *dest, char const *src)
{
	int i;

	while (src[i] != '\0') {
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}
