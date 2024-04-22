/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** cd
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#include "builtin.h"

static void get_new_pwd(mysh_t *mysh, char *pwd)
{
    if (mysh->last_cd)
        free(mysh->last_cd);
    mysh->last_cd = malloc(sizeof(char) * (my_strlen(pwd) + 1));
    mysh->last_cd[0] = '\0';
    my_strcat(mysh->last_cd, pwd);
    free(pwd);
}

static void back_to_last(mysh_t *mysh, char *pwd)
{
    if (mysh->last_cd)
        chdir(mysh->last_cd);
    get_new_pwd(mysh, pwd);
}

static void is_home_call(char *path)
{
    if (my_strcmp(path, "home") == 0)
        my_putstr("~\n");
}

bool cd_cmd(mysh_t *mysh, char *path)
{
    char *pwd = getcwd(NULL, 0);

    if (path == NULL || my_strcmp(path, "~") == 0 ||
    my_strcmp(path, "home") == 0) {
        is_home_call(path);
        get_new_pwd(mysh, pwd);
        chdir(mysh->home_cd);
        return true;
    }
    if (my_strcmp(path, "-") == 0) {
        back_to_last(mysh, pwd);
        return true;
    }
    if (chdir(path) == -1) {
        perror("cd");
        free(pwd);
    } else
        get_new_pwd(mysh, pwd);

    return true;
}
