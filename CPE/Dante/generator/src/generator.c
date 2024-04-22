/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "generator.h"

static void perfect_generation(gen_t *generator, int path, int place)
{
    for (int i = 0; i < generator->x; i++) {
        if ((i == path && IS_WALLS) || (IS_EXIT)) {
            printf("*");
            continue;
        }
        (place % 2 == 0) ? printf("*") : printf("X");
    }
}

static void imperfect_generation(gen_t *generator, int path, int place)
{
    int random_broke = 0;

    for (int i = 0; i < generator->x; i++) {
        random_broke = rand() % (generator->x + 1);
        if (((i == random_broke || i == path) && IS_WALLS) || (IS_EXIT)) {
            printf("*");
            continue;
        }
        (place % 2 == 0) ? printf("*") : printf("X");
    }
}

int generator_engine(gen_t *generator)
{
    srand(time(NULL));

    int possible_path = 0;

    for (int i = 0; i < generator->y; i++) {
        possible_path = rand() % generator->x;
        if (i == 1 && generator->y == 2)
            possible_path = generator->x - 1;
        if (generator->x == 2)
            possible_path = 1;
        if (generator->perfect)
            perfect_generation(generator, possible_path, i);
        else
            imperfect_generation(generator, possible_path, i);
        if (IS_LAST_LINE)
            printf("\n");
    }
    free(generator);
    return EXIT_SUCCESS;
}
