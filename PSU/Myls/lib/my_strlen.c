/*
** EPITECH PROJECT, 2022
** my strlen
** File description:
** count and returns the number of characters found in the string
** passed as parameter
*/

#include "../include/lib.h"

int my_strlen(char const *str)
{
    int nbcount = 0;
    while (str[nbcount] != '\0') {
        nbcount++;
    }
    return (nbcount);
}
