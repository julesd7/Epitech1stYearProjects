/*
** EPITECH PROJECT, 2022
** LIB
** File description:
** str cat
*/

#include "../include/lib.h"

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    for (i = 0; src[i] != '\0'; i++)
        dest[l + i] = src[i];
    dest[l + i] = '\0';

    return dest;
}
