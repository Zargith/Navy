/*
** EPITECH PROJECT, 2017
** my_strcat.c
** File description:
** Function that concatenates two string.
*/

#include <stdlib.h>

char *my_strcat(char *dest, char const *src)
{
	int i = 0;
	int j = 0;

	if (dest == NULL)
		dest[0] = '\0';
	if (src == NULL)
		return (dest);
	for (i = 0; dest[i] != '\0'; i++);
	while (src[j] != '\0') {
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}
