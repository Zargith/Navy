/*
** EPITECH PROJECT, 2017
** my_getnbr.c
** File description:
** Program that returns a number, sent to the function as a string.
*/

#include <my.h>

int my_getnbr(char const *str)
{
	int i = 0;
	int s = 1;
	int nb = 0;

	if (*str == '-' || *str == '+') {
		if (*str == '-')
			s = - s;
		i += 1;
	}
	if (str[i] < '0' || str[i] > '9')
		i += 1;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9') {
		nb = nb * 10 + (str[i] - '0');
		i += 1;
	}
	nb = nb * s;
	if (nb < -2147483648 || nb > 2147483647 || str[i] != '\0')
		return (0);
	else
		return (nb);
}
