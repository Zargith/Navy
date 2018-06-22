/*
** EPITECH PROJECT, 2018
** recup_nbr.c
** File description:
** recup the nbr from the signal.
*/

#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include "navy.h"

void handler_recup_nbr(int signal, siginfo_t *info, void *test)
{
	info = info;
	test = test;
	if (signal == SIGUSR1) {
		g_nbr_signal += 1;
		return;
	}
	g_nbr_signal *= 10;
}

int wait_recup_nbr(int pid)
{
	while (g_nbr_signal < 10) {
		if (kill(pid, SIGUSR2) == -1)
			return (-1);
		usleep(100);
	}
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	return (g_nbr_signal);
}

int recup_nbr(int pid_ennemy)
{
	struct sigaction new;
	int nbr = 0;

	g_nbr_signal = 0;
	new.sa_sigaction = &handler_recup_nbr;
	new.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &new, NULL) == -1)
		return (-1);
	nbr = wait_recup_nbr(pid_ennemy);
	if (nbr == -1)
		return (-1);
	nbr /= 10;
	return (nbr);
}
