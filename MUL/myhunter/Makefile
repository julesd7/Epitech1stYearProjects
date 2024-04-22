##
## EPITECH PROJECT, 2022
## my_hunter
## File description:
## Makefile
##

INCLUDE			=	-I./include/
SRCPATH 		=	./src
INITIALPATH		=	$(SRCPATH)/initialisation
EVENTPATH 		=	$(SRCPATH)/events
UTILPATH		=	$(SRCPATH)/utilities
PARAMS			=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c				\
			$(INITIALPATH)/init_music.c		\
			$(INITIALPATH)/init_sprite.c	\
			$(INITIALPATH)/init_text.c		\
			$(INITIALPATH)/init_texture.c	\
			$(INITIALPATH)/init_utilities.c	\
			$(INITIALPATH)/init_vector.c	\
			$(EVENTPATH)/poll_event.c		\
			$(EVENTPATH)/utilities_events.c	\
			$(EVENTPATH)/vector_events.c	\
			$(UTILPATH)/animate.c			\
			$(UTILPATH)/is_game_over.c		\
			$(UTILPATH)/itoa.c				\
			$(UTILPATH)/renders.c			\

NAME 	= 	hunter

all: 		$(NAME)

$(NAME):
			gcc -o $(NAME) $(SRC) $(INCLUDE) $(PARAMS)

clean:
			rm -f $(NAME)

fclean:		clean
			rm -f $(NAME)

re: 		fclean all

.PHONY: all clean fclean re
