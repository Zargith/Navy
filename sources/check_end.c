/*
** EPITECH PROJECT, 2018
** check_end.c
** File description:
** check the boards if we win or loose.
*/

#include "navy.h"

void print_boards(game *data)
{
	my_putstr("\nmy positions:\n");
	navy_display_double_array(data->board);
	my_putstr("\nenemy's positions:\n");
	navy_display_double_array(data->other_board);
}

int check_line_board(char *str)
{
	int i = 0;
	int j = 0;

	for (j = 0; str[j] != '\0'; j++) {
		if (str[j] == 'x')
			i += 1;
	}
	return (i);
}

int check_board_end(char **board)
{
	int i = 0;
	int nbr = 0;

	for (i = 0; board[i] != NULL; i++)
		nbr += check_line_board(board[i]);
	return (nbr);
}

int check_end(game *data)
{
	if (data == NULL || data->board == NULL || data->board == NULL)
		return (84);
	if (check_board_end(data->other_board) == 14) {
		print_boards(data);
		my_putstr("\nI won\n");
		return (0);
	}
	if (check_board_end(data->board) == 14) {
		print_boards(data);
		my_putstr("\nEnemy won\n");
		return (1);
	}
	return (-1);
}
