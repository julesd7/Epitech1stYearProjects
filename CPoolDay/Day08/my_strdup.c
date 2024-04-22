/*
** EPITECH PROJECT, 2022
** my strdup
** File description:
** my strdup
*/

#include <stdlib.h>

char *my_strcpy(char *dest, char const *src);

int my_strlen(char const *str);

char *my_strdup(char const *src)
{
    int l = my_strlen(src);
    char *res = malloc(l);

    res = my_strcpy(res, src);
    res[l] = '\0';
    return res;
}
