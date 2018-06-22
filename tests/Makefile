##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## UnitTest Makefile
##

SRC_DIR		=	$(realpath ..)

SRC		=	$(SRC_DIR)/sources/touched_watered.c		\
			$(SRC_DIR)/sources/board_double_array.c		\

SRC_UT_DIR	=	$(realpath .)

SRC_UT		= 	$(SRC_UT_DIR)/test_touched_watered.c		\

INC		=	-I ../includes -I ../lib/my/includes

LIBS		=	-L ../lib/my -lmy

OBJ		= 	$(SRC:%.c=%.o) $(SRC_UT:%.c=%.o)

CFLAGS		= 	$(INC) -Wall -Wextra --coverage

LIB		=	make -C ../lib/my/

LDFLAGS		= 	-lcriterion -lgcov

CC		=	gcc

NAME		=	units

all		: 	$(NAME)

$(NAME)		: 	$(OBJ)
			$(LIB)
			$(CC) -o $(NAME) $(OBJ) $(LDFLAGS) $(INC) $(LIBS)

clean		:
			rm -f $(OBJ)
			make fclean -C ../lib/my/

fclean		: 	clean
			rm -f $(NAME)
			rm -f *.gcda
			rm -f *.gcno
			rm -f ../sources/*.gcda
			rm -f ../sources/*.gcno
			make fclean -C ../lib/my/

re		: 	fclean all
