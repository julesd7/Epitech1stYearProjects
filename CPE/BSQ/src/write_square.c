/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** write square
*/

#include "my.h"
#include "bsq.h"

void write_square(char **map, int best_square, int b_col, int b_row)
{
    for (int i = 0; i < best_square; i++) {
        for (int j = 0; j < best_square; j++) {
            map[b_row + i][b_col + j] = 'x';
        }
    }
}
