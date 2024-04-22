/*
** EPITECH PROJECT, 2022
** my str isalpha
** File description:
** returns 1 if the string passed as parameter
** only contains alphabetical characters and 0 if
** the string contains another type of character.
*/

int my_str_isalpha(char const *str)
{
    int i = 0;
    int v = 0;

    if (str[0] == '\0')
        return 1;
    while (str[i] != '\0') {
        if (str[i] < 65 || (str[i] > 90 && str[i] < 97) || str[i] > 122)
            v = 1;
        i++;
    }
    if (v == 1)
        return 0;
    else
        return 1;
}
