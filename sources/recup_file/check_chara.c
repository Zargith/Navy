/*
** EPITECH PROJECT, 2018
** check_chara.c
** File description:
** check the chararcters in the file.
*/

#include "navy.h"

int my_chara_is_uppercase(char a, char b)
{
	if (!(a >= 'A' && a <= 'H'))
		return (-1);
	if (!(b >= 'A' && b <= 'H'))
		return (-1);
	return (0);
}

int my_chara_is_num(char a, char b)
{
	if (!(a >= '1' && a <= '8'))
		return (-1);
	if (!(b >= '1' && b <= '8'))
		return (-1);
	return (0);
}

int check_coord_chara(char a, char b, char c, char d)
{
	if (my_chara_is_uppercase(a, c) == -1)
		return (-1);
	if (my_chara_is_num(b, d) == -1)
		return (-1);
	return (0);
}
