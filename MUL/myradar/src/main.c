/*
** EPITECH PROJECT, 2023
** my_radar
** File description:
** main.c
*/

#include "radar.h"

static int print_help(void)
{
    my_putstr("Air traffic simulation panel\n\n");
    my_putstr("USAGE\n ./my_radar [OPTIONS] path_to_script\n");
    my_putstr("  path_to_script    The path to the script file\n\n");
    my_putstr("OPTIONS\n -h                print the usage and quit.\n\n");
    my_putstr("USER INTERACTIONS\n");
    my_putstr(" 'L' key        enable/disable hitboxes and areas.\n");
    my_putstr(" 'S' key        enable/disable sprites.\n");
    return 0;
}

int main(int ac, char **av)
{
    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        return print_help();
    else if (ac == 2 && av[1][0] != '-' && av[1][1] != 'h')
        return get_informations(ac, av);
    else
        return 84;
}
