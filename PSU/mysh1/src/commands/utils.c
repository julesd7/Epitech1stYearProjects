/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** cmd/utils
*/

#include <stdlib.h>

#include "mysh.h"
#include "builtin.h"

void free_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}

void cmd_not_found(char *cmd)
{
    my_putstr(cmd);
    my_putstr(": Command not found.\0");
    my_putchar('\n');
    exit(1);
}

bool get_bool(bool str)
{
    if (str == false)
        return true;
    else
        return false;
}

int is_false(char *temp, char *shell, int place, int i)
{
    if (shell[i] != ' ' && my_is_printable(shell[i]) == 1) {
        temp[place] = shell[i];
        place++;
    }
    if (shell[i] == ' ' && place != 0) {
        temp[place] = '#';
        place++;
    }
    return place;
}

int is_true(char *temp, char *shell, int place, int i)
{
    temp[place] = shell[i];
    place++;
    return place;
}
