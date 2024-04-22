/*
** EPITECH PROJECT, 2022
** my str isalpha
** File description:
** returns 1 if the char passed as parameter
** only contains alphabetical characters and 0 if
** the char contains another type of character.
*/

#include "../include/lib.h"

int is_alpha(char const c)
{
    if (c < 65 || (c > 90 && c < 97) || c > 122)
        return 0;
    else
        return 1;
}

int my_str_is_alpha(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (is_alpha(str[i]) == 0)
            return 0;
    }
    return 1;
}
