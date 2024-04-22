/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** check_verification
*/

#include <stdlib.h>

#include "mysh.h"

static void reset(check_t *check)
{
    check->is_pipe = false;
    check->is_semi = false;
    check->is_redirect_out = false;
    check->is_redirect_in = false;
    check->is_double_redirect_out = false;
    check->is_double_redirect_in = false;
}

static void change_values(check_t *check, char **cmd, int line)
{
    for (int j = 0; cmd[line][j] != '\0'; j++) {
        if (cmd[line][j] == '|')
            check->is_pipe = true;
        if (cmd[line][j] == ';')
            check->is_semi = true;
        if (my_strcmp(cmd[line], ROUT) == 0)
            check->is_redirect_out = true;
        if (my_strcmp(cmd[line], RIN) == 0)
            check->is_redirect_in = true;
        if (my_strcmp(cmd[line], RROUT) == 0)
            check->is_double_redirect_out = true;
        if (my_strcmp(cmd[line], RRIN) == 0)
            check->is_double_redirect_in = true;
    }
}

void check_verification(check_t *check, char **cmd)
{
    reset(check);
    for (int i = 0; cmd[i] != NULL; i++)
        change_values(check, cmd, i);
}
