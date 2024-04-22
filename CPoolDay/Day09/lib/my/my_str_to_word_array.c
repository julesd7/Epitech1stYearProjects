/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include <stdlib.h>

int my_strlen(char const *str);

static int verify_charac(char verif, int nb)
{
    if (nb == 1) {
        if (verif >= 33 && verif <= 126)
            return 1;
    }
    return 0;
}

static int get_len(char const *str, int i)
{
    while (str[i] != '\0') {
        if (verify_charac(str[i], 1) != 1)
            return i;
        i++;
    }
    return i;
}

static int get_nb(char const *str)
{
    int in = my_strlen(str);
    return in;
}

char **my_str_to_word_array(char const *str)
{
    int z = get_nb(str);
    char **res = malloc(sizeof(char *) * z + 1);
    int i = 0, n = 0, x = 0;
    while (n < z) {
        x = 0;
        res[n] = malloc(sizeof(char) * get_len(str, i));
        while (verify_charac(str[i], 1) != 0 && str[i] != '\0') {
            res[n][x] = str[i];
            x++;
            i++;
        }
        res[n][x] = '\0';
        i++;
        n++;
    }
    return res;
}
