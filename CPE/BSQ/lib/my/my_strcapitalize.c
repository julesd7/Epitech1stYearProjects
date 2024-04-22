/*
** EPITECH PROJECT, 2022
** str capitalize
** File description:
** capitalizes the first letter of each word
*/

#include "my.h"

char *my_strcapitalize(char *str)
{
    int i = -1;
    int w = 1;

    while (str[(i = i + 1)] != '\0') {
        if (str[i] <= 'Z' && str[i] >= 'A' && w == 0)
            str[i] = str[i] + 32;
        if (str[i] <= 'Z' && str[i] >= 'A' && w == 1)
            w = 0;
        if (str[i] <= '9' && str[i] >= '0' && w == 1)
            w = 0;
        if (str[i] <= 'z' && str[i] >= 'a' && w) {
            w = 0;
            str[i] = str[i] - 32;
        }
        if (str[i] == ' ' || str[i] == '-' || str[i] == '+')
            w = 1;
    }
    return str;
}
