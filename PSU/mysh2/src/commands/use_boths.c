/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** use_boths
*/

#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"

static char search_sign(char *cmd)
{
    for (int i = 0; cmd[i] != '\0'; i++) {
        if (cmd[i] == '|')
            return '|';
    }
    return ';';
}

static char *get_cmd(mysh_t *mysh, char **old_cmd)
{
    char *cmd_str = NULL;
    int size = 0;

    for (int i = 0; old_cmd[i] != NULL; i++)  {
        size += my_strlen(old_cmd[i]);
        size ++;
    }

    cmd_str = malloc(sizeof(char) * (size + 1));
    cmd_str[0] = '\0';

    for (int i = 0; old_cmd[i] != NULL; i++)  {
        my_strcat(cmd_str, old_cmd[i]);
        if (old_cmd[i + 1] != NULL &&
        my_strcmp(old_cmd[i], SEMI) != 0 &&
        my_strcmp(old_cmd[i + 1], SEMI) != 0)
        my_strcat(cmd_str, " ");
    }
    return cmd_str;
}

void use_both(mysh_t *mysh, check_t *check, char **old_cmd)
{
    char *cmd_str = get_cmd(mysh, old_cmd);
    char **cmds = my_strtowarray(cmd_str, ';');
    char **to_send = NULL;

    for (int i = 0; cmds[i] != NULL; i++) {
        if (search_sign(cmds[i]) == '|') {
            to_send = my_strtowarray(cmds[i], ' ');
            use_pipes(mysh, check, to_send);
            free_array(to_send);
        } else {
            to_send = my_strtowarray(cmds[i], ' ');
            use_command(mysh, check, to_send);
            free_array(to_send);
        }
    }
    free(cmd_str);
    free_array(cmds);
}
