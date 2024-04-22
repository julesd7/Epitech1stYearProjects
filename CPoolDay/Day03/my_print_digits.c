/*
** EPITECH PROJECT, 2022
** my print digits
** File description:
** display digits in ascending order
*/

int my_print_digits(void)
{
    char nmbr;
    nmbr = '0';

    while (nmbr <= '9') {
        my_putchar(nmbr);
        nmbr++;
    }
}
