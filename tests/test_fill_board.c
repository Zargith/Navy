/*
** EPITECH PROJECT, 2017
** test_fill_board.c
** File description:
** test fill_board function.
*/

#include "navy.h"
#include <criterion/criterion.h>

Test(fill_board, good_outputs)
{
	char **board_to_check;
	char board[8][8] = {{"........"},
			{"........"},
			{"........"},
			{"........"},
			{"........"},
			{"........"},
			{"........"},
			{"........"}};

	board_to_check = fill_double_array();
	cr_assert_arr_eq(board, board_to_check);
	for (int y = 0; y < 9; y++)
		free(board_to_check[y]);
	free(board_to_check);
}

Test(fill_board, bad_outputs)
{
	char **board_to_check;
	char board[8][8] = {{".0......"},
			{".:......"},
			{"........"},
			{"......!."},
			{"........"},
			{"... ...."},
			{"....z..."},
			{"A......."}};

	board_to_check = fill_double_array();
	cr_assert_arr_neq(board_to_check, board);
	for (int y = 0; y < 9; y++)
		free(board_to_check[y]);
	free(board_to_check);
}
