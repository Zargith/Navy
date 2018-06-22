/*
** EPITECH PROJECT, 2018
** recup_pid_player2.c
** File description:
** Main for Navy project.
*/

#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "navy.h"

int g_nbr_signal = 0;

void handler_recup_pid(int signal, siginfo_t *info, void *test)
{
	test = test;
	if (signal == SIGUSR1)
		g_nbr_signal = info->si_pid;
}

int recup_pid_signal(void)
{
	struct sigaction new;

	g_nbr_signal = 0;
	new.sa_sigaction = &handler_recup_pid;
	new.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &new, NULL) == -1)
		return (-1);
	if (sigaction(SIGUSR2, &new, NULL) == -1)
		return (-1);
	return (0);
}

int recup_pid(void)
{
	int pid = 0;

	pid = getpid();
	if (pid == -1) {
		write(2, "Error: Failed to recup pid.\n", 28);
		return (-1);
	}
	my_putstr("my_pid:  ");
	my_put_nbr(pid);
	my_putchar('\n');
	return (pid);
}

int check_connexion(int pid)
{
	if (usleep(2) == -1)
		return (-1);
	if (kill(pid, SIGUSR1) == -1) {
		write(2, "Error: Unable to connect\n", 25);
		return (-1);
	}
	signal(SIGUSR1, SIG_IGN);
	signal(SIGUSR2, SIG_IGN);
	my_putstr("enemy connected\n");
	return (0);
}

int recup_pid_from_player2(void)
{
	int pid = 0;

	if (recup_pid() == -1)
		return (-1);
	my_putstr("waiting for enemy connection...\n\n");
	if (recup_pid_signal() == -1)
		return (-1);
	while (g_nbr_signal == 0)
		pause();
	pid = g_nbr_signal;
	if (check_connexion(pid) == -1)
		return (-1);
	return (pid);
}
