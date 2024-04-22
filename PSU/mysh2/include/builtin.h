/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** builtin.h
*/

#ifndef _BUILTIN_H
    #define _BUILTIN_H

    #include "mysh.h"

    bool exit_cmd(mysh_t *mysh, char **cmd);
    bool cd_cmd(mysh_t *mysh, char *path);
    bool env_cmd(mysh_t *mysh);
    bool setenv_cmd(mysh_t *mysh, char **cmd);
    bool unsetenv_cmd(mysh_t *mysh, char **cmd);

    /*Setenv utils*/
    bool print_error(char const *name, char const *message);
    bool is_fail(mysh_t *mysh, char **cmd);
    char *get_info(char **cmd, int place);

#endif /* !_BUILTIN_H */
