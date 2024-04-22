/*
** EPITECH PROJECT, 2022
** my is prime
** File description:
** returns 1 if the number is prime and 0 if not.
*/

#include "my.h"

int my_is_prime(int nb)
{
    int i = 2;

    if (nb < 2)
        return 0;
    while (i <= nb / 2) {
        if ((nb % i) == 0)
            return 0;
        i++;
    }
    return 1;
}
