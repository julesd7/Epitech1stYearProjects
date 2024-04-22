/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** prepare_buf.c
*/

#include <unistd.h>
#include <stdlib.h>

#include "my_ls.h"

static int prepare_without_file(my_ls_t *my_ls, char *file)
{
    my_ls->buffer = open_file(file);
    my_ls->filepath = malloc(sizeof(char *) * 1);
    my_ls->filepath[1] = NULL;
    my_ls->filepath[0] = malloc(sizeof(char *) * 1);
    my_strcat(my_ls->filepath[0], ".");
    return EXIT_SUCCESS;
}

static int prepare_with_file(my_ls_t *my_ls, char **file)
{
    for (int i = 1; file[i] != NULL; i++) {
        if (file[i][0] != '-') {
            my_ls->buffer = open_file(file[i]);
            my_ls->filepath = malloc(sizeof(char *) * 2);
            my_ls->filepath[1] = NULL;
            my_ls->filepath[0] = malloc(sizeof(char *) *
            (my_strlen(file[i]) + 1));
            my_strcat(my_ls->filepath[0], file[i]);
            return EXIT_SUCCESS;
        }
    }
    return EXIT_FAIL;
}

static int prepare_with_files(my_ls_t *my_ls, char **files)
{
    NULL;
}

int prepare_without_option(my_ls_t *my_ls, char **av)
{
    if (my_ls->nb_files == 0)
        return prepare_without_file(my_ls, ".");
    if (my_ls->nb_files == 1)
        return prepare_with_file(my_ls, av);
    return prepare_with_files(my_ls, av);
}

int prepare_with_option(options_t *options, my_ls_t *my_ls, char **av)
{
    prepare_without_option(my_ls, av);

    if (options->opt_lo_r == 1)
        my_reverse_str(my_ls->buffer);
}
