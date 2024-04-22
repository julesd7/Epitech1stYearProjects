/*
** EPITECH PROJECT, 2023
** minishell
** File description:
** init_check
*/

#include <stdlib.h>

#include "mysh.h"

check_t *init_check(void)
{
    check_t *check = malloc(sizeof(mysh_t));

    check->is_pipe = false;
    check->is_semi = false;
    check->is_redirect_out = false;
    check->is_redirect_in = false;
    check->is_double_redirect_out = false;
    check->is_double_redirect_in = false;

    return check;
}
