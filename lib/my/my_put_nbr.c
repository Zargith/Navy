/*
** EPITECH PROJECT, 2017
** my_put_nbr.c
** File description:
** Program that displaythe number given as parameter.
*/

#include <my.h>

int my_put_nbr(int nb)
{
	int power = 1;
	int nb2;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * - 1;
	}
	nb2 = nb;
	while (nb2 > 9) {
		power = power * 10;
		nb2 = nb2 /10;
	}
	while (power > 0) {
		my_putchar(nb / power + '0');
		nb = nb % power;
		power = power / 10;
	}
	return (0);
}
