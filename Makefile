##
## EPITECH PROJECT, 2022
## B-CPE-110-LYN-1-1-BSQ-lyam.gomes [SSH: 192.168.1.15]
## File description:
## Makefile
##

CC = gcc

SRC = my_analyse.c \
		init.c \
		my_game.c \
		main.c \
		src/my_game_utils.c \
		init_main_menu.c \
		my_sound.c \
		my_putchar.c \
		src/my_cursor.c \
		my_secret_settings.c \
		my_text.c

OBJ = $(SRC:.c=.o)

CFLAGS = -W -Wall -I include -g3 -lcsfml-graphics \
-lcsfml-window -I include -lcsfml-system  -lcsfml-audio

NAME =  my_hunter

$(NAME): $(OBJ)
		rm -f $(OBJ)
		gcc $(CFLAGS) -o $(NAME) $(SRC)

all: $(NAME)

clean:
			rm -f $(OBJ)
			rm -f *.o
			rm -f *.a
fclean:
			rm -f $(NAME)
re: 		fclean all
