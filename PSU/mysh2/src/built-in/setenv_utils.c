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

static bool check_setenv_arg(char **cmd)
{
    char *variable = cmd[1];
    char first_char = variable[0];

    if ((first_char < 'A' ||
    (first_char > 'Z' && first_char < 'a') ||
    first_char > 'z') && first_char != '_')
        return print_error(
            "setenv: ",
            "Variable name must begin with a letter.\n");
    for (int i = 0; variable[i] != '\0'; i++) {
        if ((variable[i] < '0' ||
        (variable[i] > '9' && variable[i] < 'A') ||
        (variable[i] > 'Z' && variable[i] < 'a') ||
        variable[i] > 'z') && variable[i] != '_')
            return print_error(
                "setenv: ",
                "Variable name must contain alphanumeric characters.\n");
    }

    return false;
}

bool is_fail(mysh_t *mysh, char **cmd)
{
    int count = 0;

    for (int i = 0; cmd[i] != NULL; i++)
        count++;
    if (count == 1)
        return env_cmd(mysh);
    if (count >= 4)
        return print_error("setenv: ", "Too many arguments.\n");
    return check_setenv_arg(cmd);
}

char *get_info(char **cmd, int place)
{
    char *info = malloc(sizeof(char) * (my_strlen(cmd[place]) + 1));
    my_strcpy(info, cmd[place]);

    return info;
}
