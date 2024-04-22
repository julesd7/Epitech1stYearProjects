##
## EPITECH PROJECT, 2022
## make file
## File description:
## make file
##

NAME = 	do-op

SRC = 	do_op.c

OBJ = 	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):$(OBJ)
	gcc $(OBJ) -o $(NAME) -L ./../lib -I ./../include -lmy

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
