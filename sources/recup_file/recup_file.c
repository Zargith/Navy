/*
** EPITECH PROJECT, 2018
** recup_file.c
** File description:
** Recup the file in a char **.
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "navy.h"

char **put_in_array_file(char **file, int fd)
{
	char *str = NULL;

	for (int i = 0; i < 4; i++) {
		file[i] = my_get_next_line(fd);
		if (file[i] == NULL)
			return (free_map(file));
	}
	file[4] = NULL;
	str = my_get_next_line(fd);
	if (str != NULL) {
		free(str);
		return (free_map(file));
	}
	return (file);
}

char **recup_file(char *path)
{
	int fd = 0;
	char **file = malloc(sizeof(*file) * 5);

	if (file == NULL)
		return (NULL);
	fd = open(path, O_RDONLY);
	if (fd == -1) {
		write(2, "Error: failed to open file.\n", 28);
		close(fd);
		free(file);
		return (NULL);
	}
	file = put_in_array_file(file, fd);
	close(fd);
	return (file);
}
