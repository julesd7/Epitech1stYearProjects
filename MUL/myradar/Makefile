##
## EPITECH PROJECT, 2022
## my_radar
## File description:
## Makefile
##

INCLUDE			=	-I./include/
SRCPATH 		=	./src
PARAMS			=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c				\
			$(SRCPATH)/events.c				\
			$(SRCPATH)/get_informations.c	\
			$(SRCPATH)/plane.c				\
			$(SRCPATH)/show.c				\
			$(SRCPATH)/tower.c				\
			$(SRCPATH)/utils.c				\

NAME 	= 	my_radar

all: 		$(NAME)

$(NAME):
			gcc -o $(NAME) $(SRC) $(INCLUDE) $(PARAMS)

clean:
			rm -f $(NAME)

fclean:		clean

re: 		fclean all

.PHONY: all clean fclean re
