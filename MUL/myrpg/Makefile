##
## EPITECH PROJECT, 2023
## my_rpg
## File description:
## Makefile
##

INCLUDE			=	-I ./include/
GAMEPATH		=	./src/game/
SRCPATH 		=	./src/
SETTINGSPATH	=	./src/settings/
SOUNDPATH		=	./src/soundtrack/
INITPATH		=	./src/initialisation/
EVENTPATH		=	./src/event/
DESTROYPATH		=	./src/destroy/
PARAMS			=	-lcsfml-graphics -lcsfml-system -lcsfml-window -lcsfml-audio

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)main.c				\
			$(EVENTPATH)poll_event.c		\
			$(EVENTPATH)game_event.c		\
			$(EVENTPATH)dial_event.c		\
			$(SOUNDPATH)tracks.c			\
			$(SETTINGSPATH)all_options.c	\
			$(INITPATH)init_window.c		\
			$(INITPATH)init_character.c		\
			$(INITPATH)init_texture.c		\
			$(INITPATH)init_text.c			\
			$(INITPATH)init_maps.c			\
			$(INITPATH)menu_display.c		\
			$(GAMEPATH)game.c				\
			$(GAMEPATH)movement.c			\
			$(GAMEPATH)states.c				\
			$(GAMEPATH)collision_30fps.c	\
			$(GAMEPATH)collision_60fps.c	\
			$(DESTROYPATH)destroy_txt.c		\
			$(SETTINGSPATH)about_game.c		\
			$(SETTINGSPATH)display_settings.c	\


NAME 	= 	my_rpg

all:
		gcc -o $(NAME) $(SRC) $(INCLUDE) $(PARAMS)

clean:
		rm -f $(NAME)

fclean:		clean

re: 		fclean all

.PHONY: all clean fclean re
