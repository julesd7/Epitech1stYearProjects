/*
** EPITECH PROJECT, 2022
** my swap
** File description:
** swap the content of two integers
*/

#include "my.h"

void my_swap(int *a, int *b)
{
    int sv;
    sv = *a;
    *a = *b;
    *b = sv;
}
