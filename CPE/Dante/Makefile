##
## EPITECH PROJECT, 2023
## dante
## File description:
## Makefile
##

GENERATOR 		=	./generator
SOLVER 			=	./solver
CD				=	cd
&&				=	&&
clean			=	clean
fclean			=	fclean

CFLAGS += 	-Werror -Wextra -Wall -pedantic -std=c99

all:
		$(CD) $(GENERATOR) $(&&) $(MAKE)
		$(CD) $(SOLVER) $(&&) $(MAKE)

clean:
		$(CD) $(GENERATOR) $(&&) $(MAKE) $(clean)
		$(CD) $(SOLVER) $(&&) $(MAKE) $(clean)

fclean:		clean
		$(CD) $(GENERATOR) $(&&) $(MAKE) $(fclean)
		$(CD) $(SOLVER) $(&&) $(MAKE) $(fclean)

re: 		fclean all

.PHONY: all clean fclean re
