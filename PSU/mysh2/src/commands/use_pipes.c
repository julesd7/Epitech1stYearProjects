/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** use_pipes
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "mysh.h"

static void first_pipe(mysh_t *mysh, check_t *check, char **cmd)
{
    pid_t pid = fork();

    if (pid == 0) {
        dup2(mysh->pipe[1], 1);
        close(mysh->pipe[0]);
        use_command(mysh, check, cmd);
        exit(1);
    } else {
        close(mysh->pipe[1]);
        mysh->save_pipe = mysh->pipe[0];
    }

    wait(NULL);
}

static void multiple_pipe(mysh_t *mysh, check_t *check, char **cmd)
{
    pid_t pid = fork();

    if (pid == 0) {
        dup2(mysh->save_pipe, 0);
        dup2(mysh->pipe[1], 1);
        close(mysh->pipe[0]);
        use_command(mysh, check, cmd);
        exit(1);
    } else {
        close(mysh->pipe[1]);
        close(mysh->save_pipe);
        mysh->save_pipe = mysh->pipe[0];
    }

    wait(NULL);
}

static void last_pipe(mysh_t *mysh, check_t *check, char **cmd)
{
    pid_t pid = fork();

    if (pid == 0) {
        dup2(mysh->pipe[0], 0);
        close(mysh->save_pipe);
        close(mysh->pipe[1]);
        use_command(mysh, check, cmd);
        exit(1);
    } else {
        close(mysh->pipe[0]);
        close(mysh->pipe[1]);
        close(mysh->save_pipe);
    }

    wait(NULL);
}

static char **get_one_cmd(mysh_t *mysh, char **cmd, int place)
{
    char **cmd_to_return = NULL;
    char **temp_cmd = NULL;
    char *temp = NULL;
    int size = 0;

    for (int i = 0; cmd[i] != NULL; i++)
        size += my_strlen(cmd[i]) + 1;
    temp = malloc(sizeof(char) * (size + 1));
    temp[0] = '\0';
    for (int i = 0; cmd[i] != NULL; i++) {
        my_strcat(temp, cmd[i]);
        if (cmd[i + 1] != NULL && my_strcmp(cmd[i], PIPE) != 0 &&
        my_strcmp(cmd[i + 1], PIPE) != 0)
            my_strcat(temp, " ");
    }
    temp_cmd = my_strtowarray(temp, '|');
    cmd_to_return = my_strtowarray(temp_cmd[place], ' ');
    free(temp);
    free_array(temp_cmd);
    return cmd_to_return;
}

void use_pipes(mysh_t *mysh, check_t *check, char **cmd)
{
    int count = 0;
    char **cmd_temp = NULL;

    if (handle_pipe(mysh, cmd) == true)
        return;
    for (int i = 0; cmd[i] != NULL; i++)
        for (int j = 0; cmd[i][j] != '\0'; j++)
            count += is_a_pipe(cmd, i, j);
    for (int i = 0; i <= count; i++) {
        cmd_temp = get_one_cmd(mysh, cmd, i);
        if (i < count)
            pipe(mysh->pipe);
        if (i == 0)
            first_pipe(mysh, check, cmd_temp);
        if (i > 0 && i < count)
            multiple_pipe(mysh, check, cmd_temp);
        if (i == count)
            last_pipe(mysh, check, cmd_temp);
        free_array(cmd_temp);
    }
}
