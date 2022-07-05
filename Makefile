##
## EPITECH PROJECT, 2022
## MAKEFILE
## File description:
## MAKEFILE file.
##

SRC = $(shell find lib my_printf src -name '*.c')

OBJ = $(SRC:.c=.o)

CFLAGS += -I ./include -Wall -Wextra -g3

NAME = 42sh

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re
