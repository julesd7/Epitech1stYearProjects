/*
** EPITECH PROJECT, 2022
** my find prime sup
** File description:
** returns the smallest prime number that is greater than,
** or equal to, the number given as a parameter.
*/

#include "my.h"

int my_find_prime_sup(int nb)
{
    if (my_is_prime(nb))
        return nb;
    while (!my_is_prime(nb)) {
        nb = nb + 1;
    }
    return nb;
}
