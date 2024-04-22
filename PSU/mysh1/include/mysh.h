/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** mysh.h
*/

#ifndef _MYSH_H
    #define _MYSH_H

    #define EXIT_SUCCESS 0
    #define EXIT_FAIL 84
    #define HEIGHT 10
    #define LENGTH 11

    #include <stdbool.h>

    #include "lib.h"

    typedef struct mysh {
        bool isatty;
        char **env;
        char *path;
        char *home_cd;
        char *last_cd;
        int *pipe;
        int save_pipe;
        int state;
        void (*exit)(struct mysh *mysh, int state, char *msg);
    } mysh_t;

    /*Initialisation*/
    mysh_t *init_mysh(char **env);
    void init_minishell(mysh_t *mysh);

    /*Minishell engine*/
    void start_minishell(mysh_t *mysh);

    /*Checks*/
    bool is_builtin_cmd(mysh_t *mysh, char **cmd);

    /*Commands engine*/
    void use_command(mysh_t *mysh, char **cmd);

    /*Utils*/
    void copy_env(mysh_t *mysh, char **env);
    void free_array(char **array);
    void cmd_not_found(char *cmd);
    int get_size(char **env, int code, int line);
    bool get_bool(bool str);
    int is_false(char *temp, char *shell, int place, int i);
    int is_true(char *temp, char *shell, int place, int i);

#endif /* !_MYSH_H */
