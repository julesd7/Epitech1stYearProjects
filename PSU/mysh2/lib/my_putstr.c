/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** display one-by-one the characters of a string.
*/

#include <unistd.h>

#include "../include/lib.h"

int my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
    return 0;
}
