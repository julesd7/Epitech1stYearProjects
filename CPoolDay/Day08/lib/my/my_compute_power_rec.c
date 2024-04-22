/*
** EPITECH PROJECT, 2022
** my compute power rec
** File description:
** Returns the first argument raised to the power p
** where p is the second argument.
*/

int my_compute_power_rec(int nb, int p)
{
    int nbr = nb;
    if (p == 0)
        return 1;
    if (p < 0)
        return 0;
    nbr = nb * my_compute_power_rec(nb, p - 1);
    return (nbr);
}
