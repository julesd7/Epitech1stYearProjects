/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** exit
*/

#include "builtin.h"

#include <stdlib.h>

static void handle_error(char check)
{
    if ((check >= '0' && check <= '9'))
        print_error("exit: ", "Badly formed number.\n");
    else
        print_error("exit: ", "Expression Syntax.\n");
}

bool exit_cmd(mysh_t *mysh, char **cmd)
{
    int status = my_atoi(cmd[1]);

    if (status == 0 && cmd[1] != NULL) {
        if (cmd[1][1] != '\0' || cmd[1][0] - '0' != 0) {
            handle_error(cmd[1][0]);
            mysh->status = 1;
            return true;
        }
    } else
        mysh->status = status;
    mysh->exit(mysh, EXIT_SUCCESS, "exit\n");

    return true;
}
