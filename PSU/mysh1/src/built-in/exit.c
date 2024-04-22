/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** exit
*/

#include <stdlib.h>

#include "builtin.h"

bool exit_cmd(mysh_t *mysh)
{
    mysh->exit(mysh, EXIT_SUCCESS, "exit\n");

    return true;
}
