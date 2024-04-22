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

void remove_spaces(char *line)
{
    bool is_space = false;
    bool check = false;
    int place = 0;

    for (int i = 0; line[i] != '\0'; i++) {
        check = false;
        if (line[i] != '#' && line[i] != '\t') {
            line[place++] = line[i];
            is_space = false;
            check = true;
        }
        if (!is_space && check == false) {
            line[place++] = '#';
            is_space = true;
        }
    }
    line[place] = '\0';
}

static char **get_cmd(mysh_t *mysh, char *shell)
{
    char **cmd = NULL;
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
    remove_spaces(temp);
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

static void minishell(mysh_t *mysh, check_t *check)
{
    char **cmd = NULL;
    char *shell_cmd = NULL;
    size_t size = 0;

    signal(SIGINT, signal_handler);
    if (getline(&shell_cmd, &size, stdin) == -1)
        mysh->exit(mysh, EXIT_SUCCESS, mysh->isatty ? "exit\n" : NULL);
    else {
        shell_cmd[my_strlen(shell_cmd) - 1] = '\0';
        cmd = get_cmd(mysh, shell_cmd);
        check_verification(check, cmd);
        check_cmd(mysh, check, cmd);
        free_array(cmd);
    }
    if (shell_cmd)
        free(shell_cmd);
}

void start_minishell(mysh_t *mysh)
{
    check_t *check;

    if (mysh->isatty) {
        while (mysh->state == -1) {
            check = init_check();
            my_putstr("> ");
            minishell(mysh, check);
            free(check);
        }
    } else {
        while (mysh->state == -1) {
            check = init_check();
            minishell(mysh, check);
            free(check);
        }
    }
}
