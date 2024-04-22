/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** second_utils
*/

#include <string.h>

#include "mysh.h"

void handle_errors(char *name, int code)
{
    my_putstr(name);
    my_putstr(": ");
    my_putstr(strerror(code));
    my_putstr(".\n");
}

int is_a_pipe(char **cmd, int i, int j)
{
    if (cmd[i][j] == '|')
        return 1;
    return 0;
}

static bool check_pipe_handle(char **cmd, int i)
{
    for (int j = 0; cmd[i][j] != '\0'; j++) {
        if (cmd[i][j] == '|' && ((cmd[i][j + 1] == '\0' ||
        cmd[i][j + 2] == '\0') && (cmd[i + 1] == NULL)))
            return true;
    }
}

bool handle_pipe(mysh_t *mysh, char **cmd)
{
    if (cmd[0][0] == '|') {
        my_putstr("Invalid null command.\n");
        mysh->status = 1;
        return true;
    }
    for (int i = 0; cmd[i] != NULL; i++) {
        if (check_pipe_handle(cmd, i) == true) {
            my_putstr("Invalid null command.\n");
            mysh->status = 1;
            return true;
        }
    }
}
