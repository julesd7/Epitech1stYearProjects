/*
** EPITECH PROJECT, 2022
** my compute square root
** File description:
** Return the square root
*/

#include "my.h"

int my_compute_square_root(int nb)
{
    int res = 0;
    if (nb == 0 || nb < 0)
        return 0;

    while (res * res != nb) {
        res++;
        if (res > nb)
            return 0;
    }
    return (res);
}
