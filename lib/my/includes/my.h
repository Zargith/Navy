/*
** EPITECH PROJECT, 2017
** my.h
** File description:
** My library.
*/

#include <stdarg.h>
#include <stdio.h>
#ifndef _MY_H_
#define _MY_H_

void my_putchar(char c);
void my_putchar_error(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
int my_swap(int *a, int *b);
void my_putstr(char *str);
void my_putstr_error(char *str);
int my_strlen(char const *str);
int my_getnbr(char const * str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const * str);
int alpha(char const *str, int i);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
char *my_strcat(char *dest, char const * src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_show_world_array(char *const *tab);
int sum_stdarg(int i, int nb, ...);
int disp_stdarg(char *s, ...);
int my_putnbr_base(int nbr, char const *base);
void my_printf(char *str, ...);
int display(char c, va_list arg);
int display1(char c, va_list arg);
int display2(char c, va_list arg);
int display3(char c, va_list arg);
void flag_upper_s(char *arg);
void my_display_double_array(char **array);
char *my_get_next_line(int fd);
#endif
