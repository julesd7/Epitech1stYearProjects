/*
** EPITECH PROJECT, 2023
** navy
** File description:
** check_victory
*/

#include <stdlib.h>
#include <unistd.h>

#include "navy.h"

int is_loose(void)
{
    my_putstr("Enemy won\n");
    return EXIT_FAILURE;
}

int is_win(void)
{
    my_putstr("I won\n");
    return EXIT_SUCCESS;
}

int check_victory(char **map)
{
    int hits = 0;

    for (int i = 0; i < 64; i++) {
        if (map[i % 8][(i / 8) * 2] == 'x')
            hits++;
    }
    if (hits == 14)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
