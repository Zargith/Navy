##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for the lib
##

NAME	=	libmy.a

SRCS	=	my_getnbr.c			\
		my_putchar.c			\
		my_putchar_error.c		\
		my_put_nbr.c			\
		my_putstr.c			\
		my_putstr_error.c		\
		my_getnbr.c			\
		my_strcat.c			\
		my_strcmp.c			\
		my_strlen.c			\
		my_display_double_array.c 	\
		my_getnextline.c 			\

OBJ	=	$(SRCS:%.c=%.o)

INC	=	-I ./includes

CFLAGS	=	$(INC)

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		$(RM) -f $(OBJ)

fclean: 	clean
		$(RM) -f $(NAME)

re:		fclean all
