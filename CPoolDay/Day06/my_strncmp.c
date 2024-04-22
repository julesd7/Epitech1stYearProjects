/*
** EPITECH PROJECT, 2022
** my strncmp
** File description:
** Reproduce the behavior of the strcmp function.
*/

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;
    while (n > i && s1[i] == s2[i] && s1[i] && s2[i]) {
        i++;
    }
    if (i == n || s1[i] == '\0' && s2[i] == '\0')
        return 0;
    else if (s2[i] < s1[i])
        return 1;
    else
        return -1;
}
