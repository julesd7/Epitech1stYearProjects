/*
** EPITECH PROJECT, 2022
** sokoban.c
** File description:
** handle_errors.c
*/

#include "my_sokoban.h"

void error_handling(int ac, char **av)
{
    if (ac != 2)
        exit(EXIT_FAILURE);
    else {
        int fd = open(av[1], O_RDONLY);
        if (fd == -1)
            exit(EXIT_FAILURE);
    }
}
