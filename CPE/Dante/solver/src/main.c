/*
** EPITECH PROJECT, 2023
** dante/sover
** File description:
** main.c
*/

#include "solver.h"

int main(int ac, char **av)
{
    if (is_error(ac, av) == true)
        return EXIT_FAIL;
    return solver(av[1]);
}
