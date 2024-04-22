/*
** EPITECH PROJECT, 2023
** navy
** File description:
** main.c
*/

#include <stdlib.h>
#include <stdlib.h>
#include <unistd.h>

#include "navy.h"

int main(int ac, char **av)
{
    navy_t *navy = malloc(sizeof(*navy));
    if (handle(navy, ac, av) == EXIT_FAIL)
        return EXIT_FAIL;
    navy->pid = getpid();
    return start_navy(navy, av[1]);
}
