/*
** EPITECH PROJECT, 2022
** my str isnum
** File description:
** returns 1 if the string passed as parameter
** only contains digits and 0 otherwise.
*/

#include "my.h"

int my_str_isnum(char const *str)
{
    int i = 0;
    int v = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 48 || str[i] > 57)
            v = 1;
        i++;
    }
    if (v == 1)
        return 0;
    else
        return 1;
}
