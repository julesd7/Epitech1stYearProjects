/*
** EPITECH PROJECT, 2022
** my sort int array
** File description:
** sorts an integer array in
** ascending order given a pointer
** to the first element of the array and its size.
*/

#include "my.h"

static int get_mini(int *array, int size, int i)
{
    int min = array[i];
    int inmin = i;

    i++;
    while (i < size) {
        if (array[i] < min) {
            min = array[i];
            inmin = i;
        }
        i++;
    }
    return inmin;
}

void my_sort_int_array(int *array, int size)
{
    int verify = 0;
    int mini;

    while (verify < size) {
        mini = get_mini(array, size, verify);
        my_swap(&array[mini], &array[verify]);
        verify++;
    }
}
