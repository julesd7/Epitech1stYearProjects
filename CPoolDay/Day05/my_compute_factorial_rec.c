/*
** EPITECH PROJECT, 2022
** my compute factorial rec
** File description:
** Returns the factorial of the number given as a parameter.
*/

int my_compute_factorial_rec(int nb)
{
    if (nb <= 1) {
        if (nb < 0)
            return 0;
        return 1;
    } else {
        if (nb >= 13)
            return 0;
        else
            return (nb * my_compute_factorial_rec(nb - 1));
    }
}
