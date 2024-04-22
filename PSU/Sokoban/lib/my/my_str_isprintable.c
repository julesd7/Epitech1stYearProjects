/*
** EPITECH PROJECT, 2022
** my_str_isprintable
** File description:
** returns 1 if the string passed as parameter
** only contains printable characters and 0 otherwise.
*/

#include "my.h"

int my_str_isprintable(char const *str)
{
    int i = 0;
    int v = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 32 || str[i] > 126)
            v = 1;
        i++;
    }
    if (v == 1)
        return 0;
    else
        return 1;
}
