/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include "../include/my.h"

int read_it(int ac, char **av);

int main(int ac, char **av)
{
    int rf;
    char buffer[30000];

    if (ac == 1) {
        while ((rf = read(0, buffer, 30000)) > 0)
            my_putstr(buffer);
    } else
        return (read_it(ac, av));
    return 0;
}
