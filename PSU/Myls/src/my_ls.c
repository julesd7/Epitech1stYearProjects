/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls.c
*/

#include <stdlib.h>

#include "my_ls.h"

static void print_ls(my_ls_t my_ls)
{
    char is_point;

    for (int i = 0; my_ls.buffer[i] != NULL; i++) {
        is_point = my_ls.buffer[i][0];
        if (is_point != '.' && my_ls.buffer[i + 1] != NULL) {
            my_putstr(my_ls.buffer[i]);
            my_putchar(' ');
        }
        if (is_point != '.' && my_ls.buffer[i + 1] == NULL) {
            my_putstr(my_ls.buffer[i]);
        }
    }
    my_putchar('\n');
}

static void print_all_ls(my_ls_t my_ls)
{
    for (int i = 0; my_ls.buffer[i] != NULL; i++) {
        my_putstr(my_ls.buffer[i]);
        if (my_ls.buffer[i + 1] != NULL)
            my_putchar(' ');
        else
            my_putchar('\n');
    }
}

int my_ls(int ac, char **av)
{
    options_t *options = malloc(sizeof(*options));
    my_ls_t *my_ls = malloc(sizeof(*my_ls));

    if (get_options(options, ac, av) == EXIT_FAIL)
        return EXIT_FAIL;
    my_ls->nb_files = ac - options->total - 1;
    if (options->total == 0)
        prepare_without_option(my_ls, av);
    else
        prepare_with_option(options, my_ls, av);
    if (options->opt_l == 1) {
        for (int i = 0; my_ls->filepath[i] != NULL; i++)
            use_option_l((*options), my_ls->buffer, my_ls->filepath[i]);
        return EXIT_SUCCESS;
    }
    if (options->opt_a == 1)
        print_all_ls((*my_ls));
    else
        print_ls((*my_ls));
    return EXIT_SUCCESS;
}
