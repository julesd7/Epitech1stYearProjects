/*
** EPITECH PROJECT, 2022
** my strncpy
** File description:
** copies n characters from a string into another.
*/

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;
    while (n > i && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    while (n > i) {
        dest[i] = '\0';
        i++;
    }
    return dest;
}
