##
## EPITECH PROJECT, 2023
## minishell
## File description:
## Makefile
##

INCLUDE			=	-I./include/
LIB				=	-L./lib -lmy
SRCPATH 		=	./src
LIBPATH			=	./lib
BUILTPATH		=	./src/built-in
CMDPATH			=	./src/commands
INIPATH			=	./src/init
CHECKPATH		=	./src/check

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

SRC 	=	$(SRCPATH)/main.c					\
			$(INIPATH)/init_mysh.c				\
			$(INIPATH)/init_minishell.c			\
			$(CMDPATH)/utils.c					\
			$(SRCPATH)/minishell.c				\
			$(CHECKPATH)/is_builtin.c			\
			$(BUILTPATH)/cd.c					\
			$(BUILTPATH)/env.c					\
			$(BUILTPATH)/exit.c					\
			$(BUILTPATH)/setenv.c				\
			$(BUILTPATH)/setenv_utils.c			\
			$(BUILTPATH)/unsetenv.c				\
			$(CMDPATH)/use_command.c			\

LIBSRC	=	$(LIBPATH)/my_strlen.c		\
			$(LIBPATH)/my_putstr.c		\
			$(LIBPATH)/my_putchar.c		\
			$(LIBPATH)/my_strcat.c		\
			$(LIBPATH)/my_strcpy.c		\
			$(LIBPATH)/my_strcmp.c		\
			$(LIBPATH)/my_str_to_warray.c\
			$(LIBPATH)/my_str_is_alpha.c\
			$(LIBPATH)/my_is_printable.c\

OBJ 	= 	$(LIBSRC:.c=.o)

LIBNAME = 	libmy.a

NAME 	= 	mysh

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