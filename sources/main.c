/*
** EPITECH PROJECT, 2018
** main.c
** File description:
** Main for Navy project.
*/

#include "navy.h"

int check_params(int ac, char **av, game *game)
{
	if (ac == 2) {
		game->player = 1;
	} else {
		game->pid = my_getnbr(av[1]);
		if (game->pid <= 0)
			return (84);
		game->player = 2;
	}
	game->player_turn = 1;
	return (0);
}

int choose_gameloop(game *game, char **av)
{
	if (game->player == 1) {
		game->board = recup_ship(game->board, av[1]);
		if (game->board == NULL)
			return (84);
		game->pid = recup_pid_from_player2();
		if (game->board == NULL || game->pid <= 0)
			return (84);
		game->player_turn = 1;
		return (gameloop(game));
	} else {
		game->board = recup_ship(game->board, av[2]);
		if (game->board == NULL)
			return (84);
		if (waiting_connexion_to_player1(game->pid) == -1)
			return (84);
		game->player_turn = 2;
		return (gameloop(game));
	}
	return (0);
}

int main(int ac, char** av)
{
	game *game;
	int return_gameloop = 0;

	if (ac < 2 || ac > 3)
		return (84);
	game = malloc(sizeof(*game));
	if (game == NULL || check_params(ac, av, game) == 84) {
		free(game);
		return (84);
	}
	if (malloc_and_fill_double_array(game) == 84)
		return (84);
	return_gameloop = choose_gameloop(game, av);
	free_board(game);
	return (return_gameloop);
}
