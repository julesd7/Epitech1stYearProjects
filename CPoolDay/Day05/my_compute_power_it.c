/*
** EPITECH PROJECT, 2022
** my compute power it
** File description:
** Returns the first argument raised to the power p
** where p is the second argument.
*/

int my_compute_power_it(int nb, int p)
{
    int a = 1;
    int calc = nb;

    if (p == 0)
        return 1;

    if (p < 0)
        return 0;

    while (p > a) {
        nb *= calc;
        a++;
    }
        return (nb);
}
