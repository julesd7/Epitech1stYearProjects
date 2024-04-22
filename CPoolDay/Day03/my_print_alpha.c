/*
** EPITECH PROJECT, 2022
** my_print_alpha
** File description:
** displays lowercase alphabet in ascending order
*/

int my_print_alpha(void)
{
    char alpha;
    alpha = 'a';

    while (alpha <= 'z') {
        my_putchar(alpha);
        alpha++;
    }
}
