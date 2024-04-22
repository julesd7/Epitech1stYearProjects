##
## EPITECH PROJECT, 2022
## makefile
## File description:
## makefile
##

SRC =	btree_create_node.c 	\
	btree_apply_prefix.c 	\
	btree_apply_infix.c	\
	btree_apply_suffix.c	\
	btree_insert_data.c	\
	btree_search_item.c	\
	btree_level_count.c

INCLUDE =	-I./include

CFLAGS += 	$(INCLUDE)

OBJ = 	$(SRC:.c=.o)

NAME = 	libbtree.a

all: 	$(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: 	fclean all
