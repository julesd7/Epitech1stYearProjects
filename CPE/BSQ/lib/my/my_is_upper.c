/*
** EPITECH PROJECT, 2022
** my is upper
** File description:
** returns 1 if the char passed as parameter
** is uppercase alphabetical and 0 otherwise.
*/

#include "my.h"

int my_is_upper(char const c)
{
    if (c < 65 || c > 90)
        return 0;
    else
        return 1;
}
