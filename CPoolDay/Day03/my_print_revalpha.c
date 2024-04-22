/*
** EPITECH PROJECT, 2022
** my_print_revalpha
** File description:
** display alphabet in descending order
*/

int my_print_revalpha(void)
{
    char ahpla;
    ahpla = 'z';

    while (ahpla >= 'a') {
        my_putchar(ahpla);
        ahpla--;
    }
}
