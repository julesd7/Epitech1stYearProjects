/*
** EPITECH PROJECT, 2022
** my put nbr
** File description:
** display number given as parameter
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int verify = 1;
    if (nb == -2147483648) {
        my_putstr("-2147483648");
        return (0);
    }
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
