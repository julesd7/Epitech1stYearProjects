/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** strncat
*/

#include "my.h"

char *my_strncat(char *dest, char const *src, int nb)
{
    int l = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0' && nb > i; i++)
        dest[l + i] = src[i];
    dest[l + i] = '\0';

    return dest;
}
