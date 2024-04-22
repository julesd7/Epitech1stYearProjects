/*
** EPITECH PROJECT, 2022
** concat params
** File description:
** concat params
*/

#include <stdlib.h>

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src);

char *concat_params(int argc, char **argv)
{
    int i = 0;
    int nbc;

    while (i < argc) {
        nbc = nbc + (my_strlen(argv[i]) + 1);
        i++;
    }

    char *str = malloc(sizeof(char) * (nbc));
    i = 0;
    while (i < argc) {
        my_strcat(str, argv[i]);
        if (i < argc - 1) {
            my_strcat(str, "\n");
        }
        i++;
    }
    my_strcat(str, "\0");
    return str;
}
