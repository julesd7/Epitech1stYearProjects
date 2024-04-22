##
## EPITECH PROJECT, 2023
## my_paint
## File description:
## Makefile
##

INCLUDE			=	-I./include/
SRCPATH 		=	./src
INITPATH 		=	./src/initialisation
EVENPATH 		=	./src/event
UTILPATH 		=	./src/utils
DESTPATH 		=	./src/destroy
PARAMS			=	-lcsfml-graphics -lcsfml-system -lcsfml-window

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c				\
			$(INITPATH)/init_dropdown.c		\
			$(INITPATH)/init_main.c			\
			$(INITPATH)/init_write.c		\
			$(EVENPATH)/event_main.c		\
			$(EVENPATH)/check_menus.c		\
			$(EVENPATH)/check_write.c		\
			$(EVENPATH)/check_sub_file.c	\
			$(EVENPATH)/check_sub_edit.c	\
			$(EVENPATH)/sub_about.c	\
			$(EVENPATH)/sub_help.c	\
			$(UTILPATH)/dropdownmenu.c		\
			$(UTILPATH)/display_base_window.c\
			$(DESTPATH)/destroy_dropdown.c	\

NAME 	= 	my_paint

all: 		$(NAME)

$(NAME):
			gcc -o $(NAME) $(SRC) $(INCLUDE) $(PARAMS)

clean:
			rm -f $(NAME)

fclean:		clean

re: 		fclean all

.PHONY: all clean fclean re
