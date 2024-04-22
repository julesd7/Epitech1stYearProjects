/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** use_commands
*/

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <errno.h>
#include <string.h>

#include "mysh.h"
#include "builtin.h"

static char *create_path(mysh_t mysh, char *cmd, int size)
{
    char *path = malloc(sizeof(char) * (size + 1));

    path[0] = '\0';
    my_strcpy(path, mysh.path);
    my_strcat(path, "/");
    my_strcat(path, cmd);
    return path;
}

static void exect(char **cmd, char *path)
{
    int code = 2;

    if (execve(path, cmd, NULL) < 0) {
        code = errno;
        if (code == 2)
            cmd_not_found(cmd[0]);
        else
            handle_errors(cmd[0], code);
        exit(1);
    }
}

static void check_status(mysh_t *mysh, char *cmd)
{
    if (WIFEXITED(mysh->status))
        mysh->status = WEXITSTATUS(mysh->status);
    if (!WCOREDUMP(mysh->status) &&
    WIFSIGNALED(mysh->status) && WTERMSIG(mysh->status) == SIGSEGV)
        my_putstr("Segmentation fault\n");
    if (WCOREDUMP(mysh->status) &&
    WIFSIGNALED(mysh->status) && WTERMSIG(mysh->status) == SIGSEGV)
        my_putstr("Segmentation fault (core dumped)\n");
    if (!WCOREDUMP(mysh->status) &&
    WIFSIGNALED(mysh->status) && WTERMSIG(mysh->status) == SIGFPE)
        my_putstr("Floating exception\n");
    if (WCOREDUMP(mysh->status) &&
    WIFSIGNALED(mysh->status) && WTERMSIG(mysh->status) == SIGFPE)
        my_putstr("Floating exception (core dumped)\n");
}

static char *get_path(mysh_t *mysh, char **cmd, int size)
{
    char *path = NULL;
    int check = 0;

    for (int i = 0; cmd[0][i] != '\0'; i++) {
        if ( cmd[0][i] == '/')
            check = 1;
    }

    if ((cmd[0][0] == '.' && cmd[0][1] == '/') ||
    cmd[0][0] == '/' || check == 1) {
        path = malloc(sizeof(char) * (my_strlen(cmd[0]) + 1));
        path[0] = '\0';
        my_strcpy(path, cmd[0]);
    } else
        path = create_path((*mysh), cmd[0], size);
}

void use_command(mysh_t *mysh, check_t *check, char **cmd)
{
    mysh->status = 0;
    if (cmd[0] == NULL || is_builtin_cmd(mysh, cmd) == true)
        return;
    int size = my_strlen(mysh->path) + my_strlen(cmd[0]) + 1;
    char *path = get_path(mysh, cmd, size);
    pid_t pid = fork();
    if (pid == -1) {
        free(path);
        return;
    }
    if (pid == 0)
        exect(cmd, path);
    wait(&mysh->status);
    check_status(mysh, cmd[0]);
    free(path);
}
