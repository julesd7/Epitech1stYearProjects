/*
** EPITECH PROJECT, 2022
** sort word array
** File description:
** my sort word array
*/

#include "./include/my.h"

int my_sort_word_array(char **tab)
{
    int i = 0;
    int count;
    while (tab[i] != '\0') {
        count++;
        i++;
    }
    i = 0;
    while (i < count - 1) {
        if (my_strcmp(tab[i], tab[i + 1]) > 0) {
            my_swap(&tab[i], &tab[i + 1]);
            i = 0;
        } else
            i++;
    }
    return 0;
}
