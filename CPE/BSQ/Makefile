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
			$(SRCPATH)/open_map.c			\
			$(SRCPATH)/find_square.c		\
			$(SRCPATH)/write_square.c		\
			$(SRCPATH)/show_map.c			\
			$(SRCPATH)/generator.c			\
			$(SRCPATH)/check_map.c			\


NAME 	= 	bsq

all: 		$(NAME)

$(NAME):
			cd lib/my/ && make
			gcc -o $(NAME) $(SRC) -L./lib -lmy $(INCLUDE)

clean:
			rm -f $(NAME)
			cd lib/my/ && make clean

fclean:		clean
			rm -f $(NAME)
			cd lib/my/ && make fclean

re: 		fclean all

.PHONY: all clean fclean re
