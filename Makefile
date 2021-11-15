##
## EPITECH PROJECT, 2019
## makefile
## File description:
## makefile
##

CC	?=	gcc

RM	?=	rm -f

#CFLAGS	=	-Wall -Wextra

CPPFLAGS=	-I./include

SRC	=	src/navy.c		\
		src/signal.c	\
		src/signal2.c	\
		src/com.c		\
		lib/my_putchar.c	\
		lib/my_strlen.c	\
		lib/my_strcpy.c	\
		lib/my_getnbr.c	\
		lib/my_revstr.c \
		src/get_map.c	\
		src/nay_main.c	\
		src/input.c		\
		src/bin_int.c	\
		src/fct_b.c		\
		src/send.c		\
		src/get_map2.c	\
		src/player_turn.c	\
		src/check.c		\
		src/nay.c		\
		src/get_inp.c	\

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME)

debug:	CFLAGS += -g3
debug:	fclean $(NAME)

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) $(NAME)
	$(RM) *~

re:	fclean all

.PHONY:	all clean fclean re debug
