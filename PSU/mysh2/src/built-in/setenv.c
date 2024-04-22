/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** setenv
*/

#include <stdlib.h>

#include "builtin.h"

static void insert_line(mysh_t *mysh, char *newline)
{
    char **env = NULL;
    int height = get_size(mysh->env, HEIGHT, 0) + 1;
    int length = 0;

    env = malloc(sizeof(char *) * (height + 1));
    env[height] = NULL;
    for (int i = 0; mysh->env[i] != NULL; i++) {
        length = get_size(mysh->env, LENGTH, i);
        env[i] = malloc(sizeof(char) * (length + 1));
        my_strcpy(env[i], mysh->env[i]);
        env[i][length] = '\0';
    }
    length = my_strlen(newline);
    env[height - 1] = malloc(sizeof(char) * (length + 1));
    my_strcpy(env[height - 1], newline);
    env[height - 1][length] = '\0';

    free_array(mysh->env);
    copy_env(mysh, env);
    free_array(env);
}

static void create_newline(mysh_t *mysh, char *name, char *value)
{
    char *newline;
    int size = my_strlen(name) + 1;

    if (value)
        size += my_strlen(value);
    newline = malloc(sizeof(char) * (size + 1));
    my_strcpy(newline, name);
    my_strcat(newline, "=");
    if (value)
        my_strcat(newline, value);
    insert_line(mysh, newline);
    free(newline);
}

bool setenv_cmd(mysh_t *mysh, char **cmd)
{
    char *name;
    char *value = NULL;

    if (is_fail(mysh, cmd) == true) {
        mysh->status = 1;
        return true;
    }
    name = get_info(cmd, 1);
    unsetenv_cmd(mysh, cmd);
    if (cmd[2] != NULL)
        value = get_info(cmd, 2);
    create_newline(mysh, name, value);
    free(name);
    if (value)
        free(value);

    return true;
}
