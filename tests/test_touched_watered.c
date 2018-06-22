/*
** EPITECH PROJECT, 2017
** test_touched_watered.c
** File description:
** test touched_watered function.
*/

#include "navy.h"
#include <criterion/criterion.h>

Test(touched_watered, good_inputs)
{
	game *game = malloc(sizeof(*game));

	malloc_and_fill_double_array(game);
	game->board[1][1] = '2';
	game->player = 1;
	game->player_turn = 2;
	cr_assert_eq(TOUCHED, touched_watered(1, 1, game));
	free_board(game);
}

Test(touched_watered, bad_inputs)
{
	game *game = malloc(sizeof(*game));

	malloc_and_fill_double_array(game);
	game->board[1][1] = '2';
	game->player = 1;
	game->player_turn = 2;
	cr_assert_eq(WATERED, touched_watered(0, 1, game));
	free_board(game);
}
