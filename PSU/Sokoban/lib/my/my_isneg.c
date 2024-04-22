/*
** EPITECH PROJECT, 2022
** my isneg
** File description:
** display N or P is the integer is negative or positive
*/

#include "my.h"

int my_isneg(int n)
{
    if (n >= 0) {
        my_putchar('P');
    } else {
        my_putchar('N');
    }
    return 0;
}
