##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile
##

NAME	=	navy

SRCS	=	sources/main.c						\
		sources/board_double_array.c				\
		sources/navy_display_double_array.c			\
		sources/initialisation_connexion/recup_pid_player2.c 	\
		sources/initialisation_connexion/send_pid.c 		\
		sources/initialisation_connexion/waiting_connexion.c 	\
		sources/connexion/recup_nbr.c 				\
		sources/connexion/send_nbr.c 				\
		sources/touched_watered.c				\
		sources/recup_file/check_size_ships.c 			\
		sources/recup_file/check_chara.c 			\
		sources/recup_file/parsing_file.c 			\
		sources/recup_file/put_file_in_map.c 			\
		sources/recup_file/recup_file.c 			\
		sources/recup_file/recup_ship.c 			\
		sources/game_loop.c 					\
		sources/check_coord.c 					\
		sources/check_end.c 					\
		sources/printing_function.c 				\

OBJS	=	$(SRCS:%.c=%.o)

INC	=	-I ./includes

INC_LIB	=	-I ./lib/my/includes \

LIBS	=	-L ./lib/my -lmy \

LIB	=	make -C lib/my/

CFLAGS	=	$(INC) $(INC_LIB) -Wextra -Wall

CC	=	gcc

all:		$(NAME)

$(NAME):	$(OBJS)
		$(LIB)
		$(CC) -o $(NAME) $(OBJS) $(LIBS)

clean:
		$(RM) -f $(OBJS)
		make clean -C lib/my/

fclean:		clean
		$(RM) -f $(NAME)
		make fclean -C lib/my/

re:		fclean all

tests_run :
		make -C tests/
		./tests/units

tests_fclean :
		make fclean -C tests/

debug:		CFLAGS += -g
debug:		re
