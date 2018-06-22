/*
** EPITECH PROJECT, 2018
** waiting_connexion.c
** File description:
** Main for Navy project.
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

void handler_wait_connexion(int signal, siginfo_t *info, void *test)
{
	test = test;
	if (signal == SIGUSR1)
		g_nbr_signal = info->si_pid;
}

int send_pid_to_ennemy(int enemy_pid)
{
	struct sigaction new;

	if (recup_pid() == -1)
		return (-1);
	g_nbr_signal = 0;
	new.sa_sigaction = &handler_wait_connexion;
	new.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new, NULL) == -1 || \
sigaction(SIGUSR2, &new, NULL) == -1)
		return (-1);
	if (send_pid(enemy_pid) == -1)
		return (-1);
	return (0);
}

int waiting_connexion_to_player1(int enemy_pid)
{
	if (send_pid_to_ennemy(enemy_pid) == -1)
		return (-1);
	usleep(500000);
	if (g_nbr_signal != enemy_pid) {
		my_putstr("Failed to connect\n");
		return (-1);
	}
	my_putstr("successfully connected\n");
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	return (0);
}
