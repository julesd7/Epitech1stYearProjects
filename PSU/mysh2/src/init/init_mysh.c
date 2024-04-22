/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** init_mysh
*/

#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"

int get_size(char **env, int code, int line)
{
    int size = 0;

    if (code == HEIGHT) {
        for (size = 0; env[size] != NULL; size++);
    }
    if (code == LENGTH) {
        size = my_strlen(env[line]);
    }

    return size;
}

void copy_env(mysh_t *mysh, char **env)
{
    int height = get_size(env, HEIGHT, 0);
    int length = 0;

    mysh->env = malloc(sizeof(char *) * (height + 1));
    mysh->env[height] = NULL;

    for (int i = 0; env[i] != NULL; i++) {
        length = get_size(env, LENGTH, i);
        mysh->env[i] = malloc(sizeof(char) * (length + 1));
        my_strcpy(mysh->env[i], env[i]);
        mysh->env[i][length] = '\0';
    }
}

static void	exit_mysh(mysh_t *mysh, int state, char *msg)
{
    if (msg && isatty(0))
        write(1, msg, my_strlen(msg));
    mysh->state = state;
}

mysh_t *init_mysh( char **env)
{
    int pipe[2];
    mysh_t *mysh = malloc(sizeof(mysh_t));

    mysh->state = -1;
    mysh->status = EXIT_SUCCESS;
    mysh->exit = &exit_mysh;
    mysh->isatty = isatty(0);
    mysh->pipe = pipe;
    mysh->save_pipe = 0;
    mysh->last_cd = NULL;
    copy_env(mysh, env);

    return mysh;
}
