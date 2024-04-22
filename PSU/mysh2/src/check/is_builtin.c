/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** is_builtin
*/

#include <stdlib.h>

#include "mysh.h"
#include "builtin.h"

bool prepare_cd_cmd(mysh_t *mysh, char **cmd)
{
    int count = 0;

    for (; cmd[count] != NULL; count++);
    switch (count) {
    case 1:
        return cd_cmd(mysh, NULL);
        break;
    case 2:
        return cd_cmd(mysh, cmd[1]);
        break;
    default:
        print_error("cd: ", "Too many arguments.\n");
        mysh->status = 1;
        return true;
        break;
    }
}

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
        return exit_cmd(mysh, cmd);
    if (my_strcmp(cmd[0], "cd") == 0)
        return prepare_cd_cmd(mysh, cmd);
    if (my_strcmp(cmd[0], "setenv") == 0)
        return setenv_cmd(mysh, cmd);
    if (my_strcmp(cmd[0], "unsetenv") == 0)
        return unsetenv_cmd(mysh, cmd);

    return false;
}
