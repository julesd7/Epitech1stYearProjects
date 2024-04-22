/*
** EPITECH PROJECT, 2022
** my compute factorial it
** File description:
** Returns the factorial of the number given as a parameter.
*/

int my_compute_factorial_it(int nb)
{
    int stocknb = nb;
    int a = 1;

    if (nb == 1)
        return 1;

    if (nb < 0 || nb >= 13)
        return 0;

    if (nb == 0)
        return 1;

    while (stocknb > a) {
        nb = nb * (stocknb - a);
        a++;
    }
    return (nb);
}
