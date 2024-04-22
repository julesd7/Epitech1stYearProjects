/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** unsetenv
*/

#include <unistd.h>
#include <stdlib.h>

#include "builtin.h"

static void unset_line(mysh_t *mysh, int line_to_unset)
{
    char **env = NULL;
    int height = get_size(mysh->env, HEIGHT, 0) - 1;
    int length = 0;
    int place = 0;

    env = malloc(sizeof(char *) * (height + 1));
    env[height] = NULL;

    for (int i = 0; mysh->env[i] != NULL; i++) {
        if (i == line_to_unset)
            continue;
        length = get_size(mysh->env, LENGTH, i);
        env[place] = malloc(sizeof(char) * (length + 1));
        my_strcpy(env[place], mysh->env[i]);
        env[place][length] = '\0';
        place++;
    }
    free_array(mysh->env);
    copy_env(mysh, env);
    free_array(env);
}

static bool is_fail_unset(char **cmd)
{
    int count = 0;
    for (int i = 0; cmd[i] != NULL; i++)
        count++;
    if (count <= 1)
        return print_error("unsetenv: ", "Too few arguments.\n");
    if (count >= 3)
        return print_error("unsetenv: ", "Too many arguments.\n");
    return false;
}

static int search_line(mysh_t *mysh, char *name)
{
    char **check;

    for (int i = 0; mysh->env[i] != NULL; i++) {
        check = my_strtowarray(mysh->env[i], '=');
        if (my_strcmp(name, check[0]) == 0) {
            free_array(check);
            return i;
        }
        free_array(check);
    }
    return -1;
}

bool unsetenv_cmd(mysh_t *mysh, char **cmd)
{
    char *name = NULL;
    int place = 0;

    if (is_fail_unset(cmd) == true)
        return true;
    name = get_info(cmd, 1);
    place = search_line(mysh, name);
    if (place == -1) {
        free(name);
        return true;
    }
    unset_line(mysh, place);
    free(name);
    return true;
}
