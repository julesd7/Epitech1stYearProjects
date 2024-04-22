##
## EPITECH PROJECT, 2023
## fridge
## File description:
## Makefile
##

SRCPATH 	=	./src/
CC			=	gcc
RM			=	rm -f

CFLAGS		+= 	-Wextra -Wall -Wpedantic
CPPFLAGS	+=	-iquote include

SRC     	=	$(wildcard $(SRCPATH)*.c)

OBJ 		= 	$(SRC:.c=.o)

NAME 		= 	generator

all: 			$(NAME)

$(NAME):		$(OBJ)
				$(CC) -o $(NAME) $(OBJ)

clean:
				$(RM) $(OBJ)

fclean:			clean
				$(RM) $(NAME)

re: 			fclean all

.PHONY: all clean fclean re
