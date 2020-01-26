##
## EPITECH PROJECT, 2019
## matchstick
## File description:
## Makefile
##

CC	=	gcc

CFLAGS	=	-I./include -Wall -Wextra -Ofast -O3 -Os

SRC	=	source/main.c			\
		source/my_getnbr.c		\
		source/my_map.c			\
		source/my_putstr.c		\
		source/print_map.c		\
		source/my_game.c		\
		source/my_putnbr.c		\
		source/my_strlen.c		\
		source/manage_sticks.c		\
		source/player_turn.c		\
		source/ai_turn.c		\
		source/check_pipe.c		\
		source/player_turn_loop.c	\

RM	=	rm -f

NAME	=	matchstick

all: $(NAME)

$(NAME):
	$(CC) $(SRC) -o $(NAME) $(CFLAGS)

clean:
	$(RM)

fclean: clean
	$(RM) $(NAME)

re: fclean all
