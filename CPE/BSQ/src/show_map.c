/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** show map
*/

#include "my.h"
#include "bsq.h"

void show_map(char **map, int row)
{
    for (int i = 0; i < row; i++) {
        my_putstr(map[i]);
        my_putchar('\n');
    }
}
