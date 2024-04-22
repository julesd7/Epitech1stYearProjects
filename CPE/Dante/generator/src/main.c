/*
** EPITECH PROJECT, 2023
** dante
** File description:
** main
*/

#include <stdlib.h>

#include "generator.h"

int main(int ac, char **av)
{
    gen_t *generator = malloc(sizeof(*generator));

    if (handle_and_get(ac, av, generator) == true) {
        free(generator);
        return EXIT_FAIL;
    }
    return generator_engine(generator);
}
