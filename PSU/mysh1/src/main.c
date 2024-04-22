/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** main.c
*/

#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"

static void free_structs(mysh_t *mysh)
{
    free_array(mysh->env);
    if (mysh->last_cd)
        free(mysh->last_cd);
    free(mysh->path);
    free(mysh->home_cd);
    free(mysh);
}

int main(int ac, char **av, char **env)
{
    if (env == NULL)
        return EXIT_FAIL;
    mysh_t *mysh = init_mysh(env);

    init_minishell(mysh);
    start_minishell(mysh);

    free_structs(mysh);
    return EXIT_SUCCESS;
}
