/*
** EPITECH PROJECT, 2022
** my_is_printable
** File description:
** returns 1 if the char passed as parameter
** is printable and 0 otherwise.
*/

#include "../include/lib.h"

int my_is_printable(char const c)
{
    if (c < 32 || c > 126)
        return 0;
    else
        return 1;
}
