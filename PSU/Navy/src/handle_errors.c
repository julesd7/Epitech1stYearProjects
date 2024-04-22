/*
** EPITECH PROJECT, 2023
** navy
** File description:
** handle_errors.c
*/

#include "navy.h"

static int is_help(char *path)
{
    if (my_strlen(path) == 2 && my_strcmp(path, "-h") == 0) {
        my_putstr("USAGE\n");
        my_putstr("     ./navy [first_player_pid] navy_positions\
\nDESCRIPTION\n");
        my_putstr("     first_player_pid: only for the 2nd player. \
pid of the first player.\n");
        my_putstr("     navy_positions: file representing the \
positions of the ships.\n");
        return 1;
    }
    return 0;
}

int check_error(navy_t *navy, char *buf)
{
    if ('A' > buf[0] || buf[0] > 'H')
        return EXIT_FAIL;
    if ('1' > buf[1] || buf[1] > '8')
        return EXIT_FAIL;
    return EXIT_SUCCESS;
}

int handle(navy_t *navy, int ac, char **av)
{
    if (ac != 2 && ac != 3)
        return EXIT_FAIL;
    if ((ac == 2 && is_help(av[1]) == 0)) {
        navy->is_host = 1;
        return open_pos(navy, av[1]);
    }
    if (ac = 3) {
        navy->is_host = 0;
        return open_pos(navy, av[2]);
    }
    return EXIT_SUCCESS;
}
