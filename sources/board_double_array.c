/*
** EPITECH PROJECT, 2018
** board_double_array.c
** File description:
** Make a char** for the board
*/

#include "navy.h"

char **malloc_double_array(void)
{
	char **d_array = NULL;
	int line = 0;

	d_array = malloc(sizeof(*d_array) * 9);
	if (d_array == NULL)
		return (NULL);
	for (line = 0; line < 8; line++) {
		d_array[line] = malloc(sizeof(*d_array[line]) * 9);
		if (d_array[line] == NULL)
			return (NULL);
	}
	d_array[line] = NULL;
	return (d_array);
}

char **fill_double_array(void)
{
	char **d_array = NULL;

	d_array = malloc_double_array();
	if (d_array == NULL)
		return (NULL);
	for (int y = 0; y < 8; y++) {
		for (int x = 0; x < 8; x++)
			d_array[y][x] = '.';
		d_array[y][8] = '\0';
	}
	d_array[8] = NULL;
	return (d_array);
}

void free_board(game *game)
{
	if (game == NULL)
		return;
	if (game->board != NULL) {
		for (int y = 0; y < 9; y++)
			free(game->board[y]);
		free(game->board);
	}
	if (game->other_board != NULL) {
		for (int y = 0; y < 9; y++)
			free(game->other_board[y]);
		free(game->other_board);
	}
	free(game);
}

int malloc_and_fill_double_array(game *game)
{
	game->board = fill_double_array();
	game->other_board = fill_double_array();
	if (game->board == NULL || game->other_board == NULL) {
		free_board(game);
		return (84);
	}
	return (0);
}
