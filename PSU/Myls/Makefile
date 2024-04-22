##
## EPITECH PROJECT, 2023
## my_ls
## File description:
## Makefile
##

INCLUDE			=	-I./include/
LIB				=	-L./lib -lmy
SRCPATH 		=	./src
LIBPATH			=	./lib

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c				\
			$(SRCPATH)/get_options.c		\
			$(SRCPATH)/my_ls.c				\
			$(SRCPATH)/prepare_buf.c		\
			$(SRCPATH)/open_file.c			\
			$(SRCPATH)/options_l.c			\

LIBSRC	=	$(LIBPATH)/my_putstr.c			\
			$(LIBPATH)/my_strlen.c			\
			$(LIBPATH)/my_putchar.c			\
			$(LIBPATH)/my_put_nbr.c			\
			$(LIBPATH)/my_strcmp.c			\
			$(LIBPATH)/my_strcpy.c			\
			$(LIBPATH)/my_strcat.c			\
			$(LIBPATH)/my_sort.c			\
			$(LIBPATH)/my_rev.c				\

OBJ 	= 	$(LIBSRC:.c=.o)

LIBNAME = 	libmy.a

NAME 	= 	my_ls

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
