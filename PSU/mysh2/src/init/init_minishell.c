/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** init_minishell
*/

#include <stdlib.h>
#include <unistd.h>

#include "mysh.h"

static void get_cd_home(mysh_t *mysh)
{
    char **check = my_strtowarray(mysh->env[0], '=');
    int check_words = 0;
    for (int place = 0; my_strcmp(check[0], "HOME") != 0 &&
    mysh->env[place] != NULL; place++) {
        free_array(check);
        check = my_strtowarray(mysh->env[place], '=');
    }
    if (my_strcmp(check[0], "HOME") != 0)
        mysh->home_cd = NULL;
    else {
        for (check_words = 0; check[check_words] != NULL; check_words++);
        if (check_words == 1)
            mysh->home_cd = NULL;
        else {
            mysh->home_cd = malloc(sizeof(char) * (my_strlen(check[1]) + 1));
            mysh->home_cd[my_strlen(check[1])] = '\0';
            my_strcpy(mysh->home_cd, check[1]);
        }
    }
    free_array(check);
}

static void realloc_path(mysh_t *mysh, char *str)
{
    if (mysh->path)
        free(mysh->path);

    mysh->path = malloc(sizeof(char) * (my_strlen(str) + 1));
    my_strcpy(mysh->path, str);
    mysh->path[my_strlen(str)] = '\0';
}

static void get_cmd_path(mysh_t *mysh)
{
    char **path_temp = NULL;
    char **first = NULL;
    int place = 0;

    for (place = 0; (mysh->env[place][3] != 'H'); place++);
    first = my_strtowarray(mysh->env[place], '=');
    path_temp = my_strtowarray(first[1], ':');
    for (int i = 0; path_temp[i] != NULL; i++) {
        mysh->path = malloc(sizeof(char) * (my_strlen(path_temp[i]) + 4));
        mysh->path[0] = '\0';
        my_strcat(mysh->path, path_temp[i]);
        my_strcat(mysh->path, "/ls");
        if (access(mysh->path, R_OK) == 0) {
            realloc_path(mysh, path_temp[i]);
            break;
        }
        free(mysh->path);
    }
    free_array(first);
    free_array(path_temp);
}

void init_minishell(mysh_t *mysh)
{
    get_cmd_path(mysh);
    get_cd_home(mysh);
}
