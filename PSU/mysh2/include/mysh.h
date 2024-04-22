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
    #define PIPE "|"
    #define SEMI ";"
    #define ROUT ">"
    #define RIN "<"
    #define RROUT ">>"
    #define RRIN "<<"

    #include <stdbool.h>

    #include "lib.h"

    typedef struct check {
        bool is_pipe;
        bool is_semi;
        bool is_redirect_out;
        bool is_double_redirect_out;
        bool is_redirect_in;
        bool is_double_redirect_in;
    }check_t;

    typedef struct mysh {
        bool isatty;
        char **env;
        char *path;
        char *home_cd;
        char *last_cd;
        int *pipe;
        int save_pipe;
        int state;
        int status;
        void (*exit)(struct mysh *mysh, int state, char *msg);
    } mysh_t;

    /*Initialisation*/
    mysh_t *init_mysh(char **env);
    check_t *init_check(void);
    void init_minishell(mysh_t *mysh);

    /*Minishell engine*/
    void start_minishell(mysh_t *mysh);

    /*Checks*/
    void check_verification(check_t *check, char **cmd);
    void check_cmd(mysh_t *mysh, check_t *check, char **cmd);
    bool is_builtin_cmd(mysh_t *mysh, char **cmd);

    /*Commands engine*/
    void use_command(mysh_t *mysh, check_t *check, char **cmd);
    void use_semicolons(mysh_t *mysh, check_t *check, char **cmd);
    void use_pipes(mysh_t *mysh, check_t *check, char **cmd);
    void use_both(mysh_t *mysh, check_t *check, char **old_cmd);

    /*Utils*/
    void copy_env(mysh_t *mysh, char **env);
    void free_array(char **array);
    void cmd_not_found(char *cmd);
    int get_size(char **env, int code, int line);
    bool get_bool(bool str);
    int is_false(char *temp, char *shell, int place, int i);
    int is_true(char *temp, char *shell, int place, int i);
    int is_a_pipe(char **cmd, int i, int j);
    bool handle_pipe(mysh_t *mysh, char **cmd);
    void handle_errors(char *name, int code);

#endif /* !_MYSH_H */
