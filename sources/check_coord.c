/*
** EPITECH PROJECT, 2018
** check_coord.c
** File description:
** Check the coord recup and .
*/

#include "navy.h"

int send_coord(int pid, int coord1, int coord2)
{
	if (send_nbr(coord1, pid) == -1)
		return (-1);
	if (send_nbr(coord2, pid) == -1)
		return (-1);
	return (0);
}

int check_coord_and_send(game *data, char *str)
{
	int size = my_strlen(str);
	int y = 0;
	int x = 0;

	if (size != 2 || !(str[0] >= 'A' && str[0] <= 'H')) {
		my_putstr("wrong position\n");
		return (-1);
	}
	if (!(str[1] >= '1' && str[1] <= '8')) {
		my_putstr("wrong position\n");
		return (-1);
	}
	y = str[0] - 'A' + 1;
	x = str[1] - '0';
	if (send_coord(data->pid, x, y) == -1) {
		my_putstr("Failed to send\n");
		return (-1);
	}
	return (0);
}
