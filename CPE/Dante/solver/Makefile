##
## EPITECH PROJECT, 2023
## solver
## File description:
## Makefile
##

INCLUDE			=	-I./include/
SRCPATH 		=	./src

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c			\
			$(SRCPATH)/is_error.c		\
			$(SRCPATH)/solver.c			\
			$(SRCPATH)/process.c		\

NAME 	= 	solver

all: 		$(NAME)

$(NAME):
		gcc -o $(NAME) $(SRC) $(INCLUDE)

clean:
		rm -f $(NAME)

fclean:		clean

re: 		fclean all

.PHONY: all clean fclean re
