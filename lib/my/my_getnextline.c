/*
** EPITECH PROJECT, 2018
** getnextline.c
** File description:
** Function get_next_line.c
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *my_return_null(char *result)
{
	if (result == NULL) {
		result = malloc(sizeof(*result));
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
	}
	return (result);
}

char *my_strcat_special(char *dest, char src)
{
	int i = 0;

	if (dest == NULL)
		dest[0] = '\0';
	if (src == 0)
		return (dest);
	for (i = 0; dest[i] != '\0'; i++);
	dest[i] = src;
	dest[i + 1] = '\0';
	return (dest);
}

char *put_in_result(char *prev_result, char buffer)
{
	char *new_result = NULL;
	int size = my_strlen(prev_result) + 1;

	if (prev_result == NULL) {
		new_result = malloc(sizeof(*new_result) * 2);
		if (new_result == NULL)
			return (NULL);
		new_result[0] = buffer;
		new_result[1] = '\0';
	} else {
		new_result = malloc(sizeof(*new_result) * (size + 1));
		for (int i = 0; i <= size; i++)
			new_result[i] = '\0';
		if (new_result == NULL)
			return (NULL);
		new_result = my_strcat(new_result, prev_result);
		new_result = my_strcat_special(new_result, buffer);
	}
	free(prev_result);
	return (new_result);
}

char *my_get_next_line(int fd)
{
	char buffer;
	char *result = NULL;
	int readed = 0;

	readed = read(fd, &buffer, 1);
	while (readed > 0) {
		if (buffer == '\n' || buffer == '\0')
			return (my_return_null(result));
		result = put_in_result(result, buffer);
		if (result == NULL)
			return (NULL);
		readed = read(fd, &buffer, 1);
	}
	if (readed == -1) {
		free(result);
		return (NULL);
	}
	return (result);
}
