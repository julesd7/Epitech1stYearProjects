/*
** EPITECH PROJECT, 2022
** my_params_to_array
** File description:
** my params to array
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcpy(char *dest, char const *src);

char **my_str_to_word_array(char const *str);

static char *my_strdup(char const *src)
{
    int l = my_strlen(src);
    char *res = malloc(l);

    res = my_strcpy(res, src);
    res[l] = '\0';
    return res;
}

struct info_param *my_params_to_array(int ac, char **av)
{
    int	i = 0;
    struct info_param *arr;
    arr = malloc(sizeof(struct info_param) * (ac + 1));

    while (i < ac) {
        arr[i].length = my_strlen(av[i]);
        arr[i].str = av[i];
        arr[i].copy = my_strdup(av[i]);
        arr[i].word_array = my_str_to_word_array(av[i]);
        i++;
    }
    arr[i].str = 0;
    return arr;
}
