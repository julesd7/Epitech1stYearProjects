/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** setenv_utils
*/

#include <stdlib.h>

#include "builtin.h"

bool print_error(char const *name, char const *message)
{
    my_putstr(name);
    my_putstr(message);
    return true;
}

bool is_fail(char **cmd)
{
    int count = 0;
    for (int i = 0; cmd[i] != NULL; i++)
        count++;
    if (count <= 1)
        return print_error("setenv: ", "Too few arguments\n");
    if (count >= 4)
        return print_error("setenv: ", "Too many arguments\n");
    return false;
}

char *get_info(char **cmd, int place)
{
    char *info = malloc(sizeof(char) * (my_strlen(cmd[place]) + 1));
    my_strcpy(info, cmd[place]);

    return info;
}
