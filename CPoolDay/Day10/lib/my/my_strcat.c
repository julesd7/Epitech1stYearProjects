/*
** EPITECH PROJECT, 2022
** str cat
** File description:
** str cat
*/

char *my_strcat(char *dest, char const *src)
{
    int l = my_strlen(dest);
    int i = 0;

    for (i; src[i] != '\0'; i++)
        dest[l + i] = src[i];
    dest[l + i] = '\0';

    return dest;
}
