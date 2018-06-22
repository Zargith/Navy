/*
** EPITECH PROJECT, 2018
** send_pid.c
** File description:
** Main for Navy project.
*/

#include <sys/types.h>
#include <signal.h>
#include "navy.h"

int send_pid(int ennemy_pid)
{
	if (kill(ennemy_pid, SIGUSR1) == -1) {
		my_putstr("Error: Invalid pid.\n");
		return (-1);
	}
	return (0);
}
