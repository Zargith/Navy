/*
** EPITECH PROJECT, 2018
** touched_watered.c
** File description:
** Function that deal with managing of touched or watered.
*/

#include "navy.h"

int touched_watered(int x, int y, game *game)
{
	if (game->board[y][x] >= '2' && game->board[y][x] <= '5') {
		my_putstr("hit\n");
		return (TOUCHED);
	}
	my_putstr("missed\n");
	return (WATERED);
}

void applie_update(int tchd_or_wtrd, int line, int column, char **board)
{
	if (tchd_or_wtrd == TOUCHED)
		board[line][column] = 'x';
	else if (board[line][column] != 'x')
		board[line][column] = 'o';
}

void update_boards(int tchd_or_wtrd, int line, int column, game *game)
{
	if (game->player == 1) {
		if (game->player_turn == 1)
			applie_update(tchd_or_wtrd, line, column, \
game->other_board);
		else
			applie_update(tchd_or_wtrd, line, column, \
game->board);
	} else {
		if (game->player_turn == 1)
			applie_update(tchd_or_wtrd, line, column, \
game->other_board);
		else
			applie_update(tchd_or_wtrd, line, column, \
game->board);
	}
}
