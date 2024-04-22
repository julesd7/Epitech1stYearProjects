/*
** EPITECH PROJECT, 2023
** dante
** File description:
** handle_error
*/

#include <stdlib.h>
#include <string.h>

#include "generator.h"

static bool get_gen_info(int ac, char **av, gen_t *generator)
{
    generator->perfect = false;
    if (ac == 4) {
        if (strcmp(av[3], "perfect") == 0)
            generator->perfect = true;
        else
            return true;
    }
    generator->x = atoi(av[1]);
    generator->y = atoi(av[2]);
    if (generator->x <= 0 || generator->y <= 0)
        return true;
    return false;
}

static bool check_values(char *x, char *y)
{
    for (int i = 0; x[i] != '\0'; i++) {
        if (x[i] < '0' || x[i] > '9')
            return true;
    }
    for (int i = 0; y[i] != '\0'; i++) {
        if (y[i] < '0' || y[i] > '9')
            return true;
    }
    return false;
}

bool handle_and_get(int ac, char **av, gen_t *generator)
{
    if (ac < 3 || ac > 4)
        return true;
    if (check_values(av[1], av[2]) == true)
        return true;
    if (get_gen_info(ac, av, generator) == true)
        return true;
    return false;
}
