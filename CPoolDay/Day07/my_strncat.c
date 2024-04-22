/*
** EPITECH PROJECT, 2022
** strncat
** File description:
** Write a function that concatenates n characters
** of the src string to the end of the dest string.
*/

char *my_strncat(char *dest, char const *src, int nb)
{
    int l = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0' && nb > i; i++)
        dest[l + i] = src[i];
    dest[l + i] = '\0';

    return dest;
}
