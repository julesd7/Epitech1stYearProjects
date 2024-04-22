/*
** EPITECH PROJECT, 2023
** dante
** File description:
** generator_h
*/

#ifndef _GENERATOR_H
    #define _GENERATOR_H

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define IS_WALLS place % 2 == 1
    #define IS_EXIT i == generator->x - 1 && place == generator->y - 1
    #define IS_LAST_LINE generator->y > i + 1

    #include <stdbool.h>

    typedef struct generator {
        bool perfect;
        int x;
        int y;
    }gen_t;

    bool handle_and_get(int ac, char **av, gen_t *generator);
    int generator_engine(gen_t *generator);

#endif /* !_GENERATOR_H */
