/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** main.c
*/

#include <stdlib.h>

#include "bsq.h"

int main(int ac, char **av)
{
    if (ac == 1)
        return 84;
    if (ac > 3)
        return 84;
    if (ac == 2) {
        if (check_map(av) == 84)
            return 84;
        if (check_map(av) == 0)
            return new_bsq(ac, av);
    }
    if (ac == 3 && av[2][0] != '\0')
        return map_gen(av);
    else if (ac == 3 && av[2][0] == '\0')
        return 84;
}
