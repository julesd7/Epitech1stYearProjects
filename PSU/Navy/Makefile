##
## EPITECH PROJECT, 2023
## Navy
## File description:
## Makefile
##

INCLUDE			=	-I./include/
LIB				=	-L./lib -lmy
SRCPATH 		=	./src
LIBPATH			=	./lib

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c				\
			$(SRCPATH)/handle_errors.c		\
			$(SRCPATH)/create_map.c			\
			$(SRCPATH)/print_map.c			\
			$(SRCPATH)/fill_boats.c			\
			$(SRCPATH)/navy.c				\
			$(SRCPATH)/server.c				\
			$(SRCPATH)/client.c				\
			$(SRCPATH)/paquets.c			\
			$(SRCPATH)/init_sigaction.c		\
			$(SRCPATH)/check_victory.c		\
			$(SRCPATH)/shoot.c				\

LIBSRC	=	$(LIBPATH)/my_putstr.c			\
			$(LIBPATH)/my_strlen.c			\
			$(LIBPATH)/my_putchar.c			\
			$(LIBPATH)/my_put_nbr.c			\
			$(LIBPATH)/my_strcmp.c			\
			$(LIBPATH)/my_strcpy.c			\
			$(LIBPATH)/my_getnbr.c			\

OBJ 	= 	$(LIBSRC:.c=.o)

LIBNAME = 	libmy.a

NAME 	= 	navy

all: 		$(NAME)

$(NAME):	$(OBJ)
			ar rc $(LIBNAME) $(OBJ) && mv $(LIBNAME) $(LIBPATH)
			gcc -o $(NAME) $(SRC) $(LIB) $(INCLUDE)

clean:
			rm -f $(OBJ)
			rm -f $(LIBPATH)/$(LIBNAME)
			rm -f $(NAME)

fclean:		clean

re: 		fclean all

.PHONY: all clean fclean re
