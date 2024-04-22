##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

INCLUDE	=	-I ./include/

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRCPATH = ./src


SRC 	=  	$(SRCPATH)/main.c				\
			$(SRCPATH)/getmap.c				\
			$(SRCPATH)/move.c				\
			$(SRCPATH)/is_square.c			\
			$(SRCPATH)/is_case.c			\
			$(SRCPATH)/is_blocked.c			\
			$(SRCPATH)/utilities.c			\
			$(SRCPATH)/get_verif_map.c		\
			$(SRCPATH)/init.c				\
			$(SRCPATH)/key_event.c			\
			$(SRCPATH)/handle_errors.c		\

NAME 	= 	my_sokoban

all: 		$(NAME)

$(NAME):
			cd lib/my/ && make
			gcc -o $(NAME) $(SRC) -L./lib -lmy $(INCLUDE) -lncurses


clean:
			rm -f $(NAME)
			cd lib/my/ && make clean

fclean:		clean
			rm -f $(NAME)
			cd lib/my/ && make fclean

re: 		fclean all

.PHONY: all clean fclean re
