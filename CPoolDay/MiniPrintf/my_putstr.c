/*
** EPITECH PROJECT, 2022
** my putstr
** File description:
** display one-by-one the characters of a string.
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int nbc = 0;

    while (str[nbc] != '\0') {
        my_putchar(str[nbc]);
        nbc++;
    }
    return 0;
}
