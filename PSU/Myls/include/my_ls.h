/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_ls.h
*/

#ifndef _MY_LS_H
    #define _MY_LS_H

    #define EXIT_FAIL 84
    #define EXIT_SUCCESS 0

    #include "lib.h"

    typedef struct my_ls {
        char **buffer;
        char **filepath;
        int nb_files;
    }my_ls_t;

    typedef struct options {
        int opt_a;
        int opt_l;
        int opt_up_r;
        int opt_lo_r;
        int opt_d;
        int opt_t;
        int total;
    }options_t;

    int my_ls(int ac, char **av);
    int get_options(options_t *options, int ac, char **av);
    char **open_file(char *file);
    int prepare_without_option(my_ls_t *my_ls, char **av);
    int prepare_with_option(options_t *options, my_ls_t *my_ls, char **av);
    int use_option_l(options_t options, char **buffer, char *files);

#endif /* !_MY_LS_H */
