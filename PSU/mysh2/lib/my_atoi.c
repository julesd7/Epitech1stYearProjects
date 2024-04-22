/*
** EPITECH PROJECT, 2023
** lib
** File description:
** my_atoi
*/

#include <stdlib.h>

static int handle(const char *str)
{
    if ((str[0] < '0' || str[0] > '9') && str[0] != '-')
        return -1;
    for (int i = 1; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9')
            return -1;
    }
    return 0;
}

int my_atoi(const char *str)
{
    int nb = 0;
    int start = 0;
    int sign = 1;

    if (str == NULL || handle(str) == -1)
        return 0;
    if (str[0] == '-') {
        start = 1;
        sign = -1;
    }
    for (int i = start; str[i] != '\0'; i++) {
        nb += str[i] - '0';
        if (str[i + 1] != '\0')
            nb *= 10;
    }

    return nb * sign;
}
