/*
** EPITECH PROJECT, 2022
** my is num
** File description:
** returns 1 if the char passed as parameter
** is a digits and 0 otherwise.
*/

#include "my.h"

int my_is_num(char const c)
{
    if (c < 48 || c > 57)
        return 0;
    else
        return 1;
}
