##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

NAME = 	cat

SRC = 	cat.c \
	main.c \

OBJ = 	$(SRC:.c=.o)

all: 	$(NAME)

$(NAME):$(OBJ)
	$(MAKE) -C ../lib/my/
	gcc $(OBJ) -o $(NAME) -L ../lib -I ../include -lmy

tests_run:
	gcc -o unit_tests cat.c ../tests/tests.c -L ../lib \
	-I ../include/ --coverage -lcriterion -lmy
	./unit_tests

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all

.PHONY: all clean fclean re
