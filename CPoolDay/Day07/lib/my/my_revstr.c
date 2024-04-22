/*
** EPITECH PROJECT, 2022
** my revstr
** File description:
** Reverses a string.
*/

char *my_revstr(char *str)
{
    char stock;
    int l = my_strlen(str) - 1;
    int i = 0;

    while (i < l / 2) {
        stock = str[i];
        str[i] = str[l - i];
        str[l - i] = stock;
        i++;
    }
    return str;
}
