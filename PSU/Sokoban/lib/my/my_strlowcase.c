/*
** EPITECH PROJECT, 2022
** my strlowcase
** File description:
** puts every letter of every word in it in lowercase.
*/

#include "my.h"

char *my_strlowcase(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] = str[i] + 32;
        i++;
    }
    return str;
}
