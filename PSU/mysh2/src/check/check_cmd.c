/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** check_cmd
*/

#include "mysh.h"

void check_cmd(mysh_t *mysh, check_t *check, char **cmd)
{
    int reset[2];

    if (check->is_semi == true && check->is_pipe == false) {
        use_semicolons(mysh, check, cmd);
        return;
    }
    if (check->is_semi == false && check->is_pipe == true) {
        mysh->pipe = reset;
        mysh->save_pipe = 0;
        use_pipes(mysh, check, cmd);
        return;
    }
    if (check->is_semi == true && check->is_pipe == true) {
        use_both(mysh, check, cmd);
        return;
    }
    return use_command(mysh, check, cmd);
}
