/*
** EPITECH PROJECT, 2022
** str islower
** File description:
** eturns 1 if the string passed as parameter only
** contains lowercase alphabetical characters and 0 otherwise.
*/

#include "my.h"

int my_is_lower(char const c)
{
    if (c < 97 || c > 122)
        return 0;
    else
        return 1;
}
