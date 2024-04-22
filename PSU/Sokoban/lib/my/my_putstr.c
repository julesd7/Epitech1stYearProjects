/*
** EPITECH PROJECT, 2022
** my putstr
** File description:
** display one-by-one the characters of a string.
*/

#include "my.h"

int my_putstr(char const *str)
{
    int nbc = 0;

    while (str[nbc] != '\0') {
        my_putchar(str[nbc]);
        nbc++;
    }
    return 0;
}
