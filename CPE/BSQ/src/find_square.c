/*
** EPITECH PROJECT, 2022
** bsq
** File description:
** find square
*/

#include "my.h"
#include "bsq.h"

static find_square_t sqr;

static void verification_best_sqr(char **map, int actual_row, int actual_col)
{
    if ((actual_row + sqr.i) < sqr.row &&
    (actual_col + sqr.j) < sqr.col &&
    map[actual_row + sqr.i][actual_col + sqr.j] != 'o')
        NULL;
    else
        sqr.exit = 1;
}

static void verify_row(char **map, int actual_row, int actual_col)
{
    sqr.exit = 0;
    for (int i = 0; i < sqr.actual_square && sqr.exit == 0; i++) {
        sqr.i = i;
        for (int j = 0; j < sqr.actual_square; j++) {
            sqr.j = j;
            verification_best_sqr(map, actual_row, actual_col);
        }
    }
    if (sqr.exit == 0) {
        if (sqr.actual_square > sqr.best_square) {
            sqr.best_square = sqr.actual_square;
            sqr.best_col = actual_col;
            sqr.best_row = actual_row;
        }
    }
}

static int verify_col(char **map, int actual_row, int actual_col)
{
    if (map[actual_row][actual_col] == '.') {
        return 0;
    } else {
        return 1;
    }
}

static int is_square(char **map, int actual_row, int actual_col)
{
    for (int i = actual_col; i < sqr.col && map[actual_row][i] != 'o'; i++) {
        if (verify_col(map, actual_row, i) == 0) {
            verify_row(map, actual_row, actual_col);
            sqr.actual_square++;
        }
    }
}

int find_square(char **map, int col, int row)
{
    sqr.col = col;
    sqr.row = row;
    sqr.actual_square = 1;
    sqr.best_square = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; j < col;  j++) {
            is_square(map, i, j);
            sqr.actual_square = 1;
        }
    }
    int best_sqr = sqr.best_square;
    int best_col = sqr.best_col;
    int best_row = sqr.best_row;
    write_square(map, best_sqr, best_col, best_row);
    show_map(map, row);
    return 0;
}
