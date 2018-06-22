/*
** EPITECH PROJECT, 2018
** send_nbr.c
** File description:
** Main for Navy project.
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

void handler_wait_sig2(int signal, siginfo_t *info, void *test)
{
	test = test;
	info = info;
	if (signal == SIGUSR2)
		g_nbr_signal = 1;
}

int wait_sig2(void)
{
	struct sigaction new;

	g_nbr_signal = 0;
	new.sa_sigaction = &handler_wait_sig2;
	new.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR2, &new, NULL) == -1 || \
sigaction(SIGUSR1, &new, NULL) == -1)
		return (-1);
	return (0);
}

int kill_send(int nbr, int pid)
{
	int i = 0;

	for (; i < nbr; i++) {
		while (g_nbr_signal == 0)
			pause();
		g_nbr_signal = 0;
		if (kill(pid, SIGUSR1) == -1)
			return (-1);
	}
	while (g_nbr_signal == 0)
		pause();
	if (kill(pid, SIGUSR2) == -1)
		return (-1);
	return (0);
}

int send_nbr(int nbr, int pid)
{
	int error = 0;

	if (wait_sig2() == -1)
		return (-1);
	error = kill_send(nbr, pid);
	g_nbr_signal = 0;
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	return (error);
}
