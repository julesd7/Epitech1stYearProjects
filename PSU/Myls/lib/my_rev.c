/*
** EPITECH PROJECT, 2022
** my reverse str
** File description:
** reverse array content
*/

#include <stddef.h>

#include "../include/lib.h"

static void swapping(char **buffer, int place, int i)
{
    char *temp = buffer[place];
    buffer[place] = buffer[i];
    buffer[i] = temp;
}

void my_reverse_str(char **array)
{
    int length = 0;
    for (int i = 0; array[i + 1] != NULL; i++)
        length++;
    for (int i = 0; length > i; i++) {
        swapping(array, length, i);
        length--;
    }
}
