/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** minishell
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

#include "mysh.h"

static char **get_cmd(char *shell)
{
    char **cmd;
    char *temp = malloc(sizeof(char) * (my_strlen(shell) + 1));
    int place = 0;
    bool str = false;

    temp[0] = '\0';
    for (int i = 0; shell[i] != '\0'; i++) {
        if (shell[i] == '"') {
            str = get_bool(str);
            continue;
        }
        if (str == false)
            place = is_false(temp, shell, place, i);
        else
            place = is_true(temp, shell, place, i);
    }
    temp[place] = '\0';
    cmd = my_strtowarray(temp, '#');
    free(temp);
    return cmd;
}

static void signal_handler(int signal)
{
    if (signal == SIGINT)
        my_putstr("\n> ");
    return;
}

static void minishell(mysh_t *mysh)
{
    char **cmd = NULL;
    char *shell_cmd = NULL;
    size_t size = 0;

    signal(SIGINT, signal_handler);
    if (getline(&shell_cmd, &size, stdin) == -1)
        mysh->exit(mysh, EXIT_SUCCESS, mysh->isatty ? "exit\n" : NULL);
    else {
        shell_cmd[my_strlen(shell_cmd) - 1] = '\0';
        cmd = get_cmd(shell_cmd);
        use_command(mysh, cmd);
        free_array(cmd);
    }
    if (shell_cmd)
        free(shell_cmd);
}

void start_minishell(mysh_t *mysh)
{
    if (mysh->isatty) {
        while (mysh->state == -1) {
            my_putstr("> ");
            minishell(mysh);
        }
    } else {
        while (mysh->state == -1)
            minishell(mysh);
    }
}
