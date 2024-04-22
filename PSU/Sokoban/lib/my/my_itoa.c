/*
** EPITECH PROJECT, 2022
** lib/my
** File description:
** itoa.c
*/

#include <stdlib.h>

static void my_char_swap(char *first_char, char *second_char)
{
    char temp = *first_char;
    *first_char = *second_char;
    *second_char = temp;
}

static char *reverse_char(char *buffer, int first, int last)
{
    while (first < last) {
        my_char_swap(&buffer[first++], &buffer[last--]);
    }
    return buffer;
}

char *my_itoa(int value, char *buffer)
{
    int n = abs(value);
    int i = 0;
    while (n) {

        int r = n % 10;
        if (r >= 10) {
            buffer[i++] = 65 + (r - 10);
        } else {
            buffer[i++] = 48 + r;
        }
    n = n / 10;
    }
    buffer[i] = '\0';
    return reverse_char(buffer, 0, i - 1);
}
