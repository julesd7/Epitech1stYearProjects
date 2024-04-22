/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** is_builtin
*/

#include <unistd.h>

#include "mysh.h"
#include "builtin.h"

bool is_builtin_cmd(mysh_t *mysh, char **cmd)
{
    char **check = my_strtowarray(cmd[0], '/');
    int last = 0;

    for (int i = 0; check[i] != NULL; i++)
        last++;
    if (my_strcmp(check[last - 1], "env") == 0) {
        free_array(check);
        return env_cmd(mysh);
    } else
        free_array(check);
    if (my_strcmp(cmd[0], "exit") == 0)
        return exit_cmd(mysh);
    if (my_strcmp(cmd[0], "cd") == 0)
        return cd_cmd(mysh, cmd[1]);
    if (my_strcmp(cmd[0], "setenv") == 0)
        return setenv_cmd(mysh, cmd);
    if (my_strcmp(cmd[0], "unsetenv") == 0)
        return unsetenv_cmd(mysh, cmd);

    return false;
}
