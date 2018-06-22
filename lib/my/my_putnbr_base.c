/*
** EPITECH PROJECT, 2017
** my_putnbr_base.c
** File description:
** Function that convert and display a decimal number in a given base.
*/

#include <my.h>

int my_putnbr_base(int nbr, char const *base)
{
	int power = 1;
	int nb2;
	int baselen;

	baselen = my_strlen(base);
	if (nbr < 0) {
		my_putchar('-');
		nbr = nbr * -1;
	}
	nb2 = nbr;
	while (nb2 > baselen) {
		power = power * baselen;
		nb2 = nb2 / baselen;
	}
	while (power > 0) {
		my_put_nbr(nbr / power);
		nbr = nbr % power;
		power = power / baselen;
	}
	return (0);
}
