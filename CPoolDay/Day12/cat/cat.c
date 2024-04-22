/*
** EPITECH PROJECT, 2022
** cat
** File description:
** do like cat cmd
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include "../include/my.h"

int is_error(char *file_name, int code)
{
    my_puterr_str("cat: ");
    my_puterr_str(file_name);
    if (code == 2)
        my_puterr_str(": No such file or directory\n");
    if (code == 21)
        my_puterr_str(": Is a directory\n");
    return 84;
}

int read_it(int ac, char **av)
{
    int i = 1;
    int rf;
    int readrf;
    char buffer[30000];

    while (i < ac) {
        rf = open(av[i], O_RDONLY);
        if (rf == -1)
            return (is_error(av[i], errno));
        readrf = read(rf, buffer, 29999);
        if (readrf == -1)
            return (is_error(av[i], errno));
        write(1, buffer, readrf);
        i++;
    }
    close(rf);
    return 0;
}
