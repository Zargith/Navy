/*
** EPITECH PROJECT, 2018
** navy.h
** File description:
** .h for project Navy.
*/

#ifndef NAVY_H
#define NAVY_H

#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include "my.h"

extern int g_nbr_signal;

#define TOUCHED 1
#define WATERED 2

struct s_vector2i {
	int x;
	int y;	
};
typedef struct s_vector2i vector2i;

struct s_game {
	int pid;
	char **board;
	char **other_board;
	int player;
	int player_turn;
};
typedef struct s_game game;

char **fill_double_array(void);
void free_board(game *game);
int malloc_and_fill_double_array(game *game);
void navy_display_double_array(char **array);
int gameloop_player_one(game *game);
int gameloop_player_two(game *game);
int touched_watered(int column, int line, game *game);
void update_boards(int tchd_or_wtrd, int line, int column, game *game);
int return_tchd_wtrd(int tchd_wtrd, game *game, char *position);
int waiting_ennemy_attack(game *game);

int recup_pid(void);
int send_pid(int ennemy_pid);
int waiting_connexion_to_player1(int enemy_pid);
int recup_pid_from_player2(void);
int recup_nbr(int pid);
int send_nbr(int nbr, int pid);

int check_coord_chara(char a, char b, char c, char d);
int check_size_and_coord(int size, char *str);
char **parsing_file(char **file);
char **put_file_in_map(char **map, char **file);
char **recup_file(char *path);
char **recup_ship(char **map, char *path);
char **free_map(char **map);

int gameloop(game *data);
int check_coord_and_send(game *data, char *str);

int check_end(game *data);
void print_boards_loop(game *data);

void print_coord(int x, int y);
void print_if_touched(int touched, char *str);

#endif
