/*
** EPITECH PROJECT, 2018
** game_loop.c
** File description:
** Gameloop of the navy.
*/

#include <signal.h>
#include "navy.h"

int turn_player2(game *data)
{
	int x = 0;
	int y = 0;
	int touched = 0;

	my_putstr("\nwaiting for enemy's attack...\n");
	usleep(1000);
	y = recup_nbr(data->pid);
	if (y == -1)
		return (84);
	usleep(1000);
	x = recup_nbr(data->pid);
	if (x == -1)
		return (84);
	print_coord(x, y);
	touched = touched_watered(x - 1, y - 1, data);
	if (send_nbr(touched, data->pid) == -1)
		return (84);
	update_boards(touched, y - 1, x - 1, data);
	return (-1);
}

int turn_player1(game *data)
{
	int x = 0;
	int y = 0;
	int touched = 0;
	char *str = NULL;

	my_putchar('\n');
	do {
		my_putstr("attack:  ");
		str = my_get_next_line(0);
		if (str == NULL)
			return (0);
	} while (check_coord_and_send(data, str) == -1);
	x = str[0] - 'A' + 1;
	y = str[1] - '0';
	usleep(1000);
	touched = recup_nbr(data->pid);
	print_if_touched(touched, str);
	update_boards(touched, y - 1, x - 1, data);
	free(str);
	return (-1);
}

void print_boards_loop(game *data)
{
	static int turn = 0;

	if (turn % 2 != 0) {
		turn = 0;
		return;
	}
	my_putstr("\nmy positions:\n");
	navy_display_double_array(data->board);
	my_putstr("\nenemy's positions:\n");
	navy_display_double_array(data->other_board);
	turn += 1;
}

int gameloop(game *data)
{
	int end = -1;

	if (data == NULL)
		return (84);
	while (end == -1) {
		print_boards_loop(data);
		if (data->player_turn == 1) {
			end = turn_player1(data);
			data->player_turn = 2;
		} else {
			end = turn_player2(data);
			data->player_turn = 1;
		}
		if (end == -1)
			end = check_end(data);
	}
	return (end);
}
