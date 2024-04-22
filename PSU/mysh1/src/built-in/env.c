/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** env
*/

#include <stdlib.h>

#include "builtin.h"

bool env_cmd(mysh_t *mysh)
{
    for (int i = 0; mysh->env[i] != NULL; i++) {
        my_putstr(mysh->env[i]);
        my_putchar('\n');
    }

    return true;
}
