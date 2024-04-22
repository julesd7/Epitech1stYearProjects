/*
** EPITECH PROJECT, 2022
** my put nbr
** File description:
** display number given as parameter
*/

#include "../include/lib.h"

int my_put_nbr(int nb)
{
    int verify = 1;
    if (nb < 0) {
        my_putchar('-');
        nb *= -1;
    }
    while ((nb / verify) >= 10) {
        verify *= 10;
    }
    while (verify > 0) {
        my_putchar((nb / verify) % 10 + '0');
        verify /= 10;
    }
    return 0;
}
