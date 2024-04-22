/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** get_options.c
*/

#include "my_ls.h"

static int search_options(options_t *options, char **av, int i)
{
    for (int j = 1; av[i][j] != '\0'; j++) {
        if (av[i][j] == 'a')
            options->opt_a = 1;
        if (av[i][j] == 'l')
            options->opt_l = 1;
        if (av[i][j] == 'R')
            options->opt_up_r = 1;
        if (av[i][j] == 'r')
            options->opt_lo_r = 1;
        if (av[i][j] == 'd')
            options->opt_d = 1;
        if (av[i][j] == 't')
            options->opt_t = 1;
    }
}

static void init_options(options_t *options)
{
    options->opt_a = 0;
    options->opt_l = 0;
    options->opt_up_r = 0;
    options->opt_lo_r = 0;
    options->opt_d = 0;
    options->opt_t = 0;
    options->total = 0;
}

int get_options(options_t *options, int ac, char **av)
{
    int verif = 0;

    init_options(options);

    for (int i = 1; i < ac; i++) {
        if (av[i][0] == '-') {
            verif = 1;
            options->total += 1;
        }
        if (verif == 1 && search_options(options, av, i) == EXIT_FAIL)
            return EXIT_FAIL;
        verif = 0;
    }
    return EXIT_SUCCESS;
}
